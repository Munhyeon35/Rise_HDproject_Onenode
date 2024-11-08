# -*- coding: utf-8 -*-
import numpy as np
from yolov8_ros.kalmanFilter import KalmanFilter
from scipy.optimize import linear_sum_assignment
from collections import deque
from scipy.interpolate import Akima1DInterpolator
import time

max_trace = 2000 #show the maximum point of the object trajectory.

class Tracks(object):
    """docstring for Tracks"""
    def __init__(self, detection, trackId, state):
        super(Tracks, self).__init__()
        self.KF = KalmanFilter()
        self.KF.predict()
        self.KF.correct(np.matrix(detection).reshape(2,1))
        self.trace = deque(maxlen=max_trace)
        self.prediction = detection.reshape(1,2)
        self.trackId = trackId
        self.skipped_frames = 0
        # save the additional state information
        self.trace_state = deque(maxlen=max_trace)
        self.state_correction = state.reshape(1,5)  ## 241105 (1,4) -> (1,5)  To show up the label name as determining the static and dynamic
        
    def predict(self, detection=None):
        self.prediction = np.array(self.KF.predict()).reshape(1, 2)
        self.KF.correct(np.matrix(detection).reshape(2, 1))
        
    def correction(self, state=None):
        self.state_correction = state.reshape(1,5)  ## 241105 (1,4) -> (1,5)


class Tracker(object):
    """docstring for Tracker"""
    def __init__(self, dist_threshold, max_frame_skipped, max_trace_length):
        super(Tracker, self).__init__()
        self.dist_threshold = dist_threshold
        self.max_frame_skipped = max_frame_skipped
        self.max_trace_length = max_trace_length
        self.trackId = 0
        self.tracks = []
        self.MOTA_errors = {'fp': 0.0, 'miss': 0.0, 'mme': 0,'gt': 0.0 }
        self.MOTP_errors = {'dit': 0.0, 'ct': 0.0, 'dmax': [0.0]}
        self.gt_count = 2
        self.assignment_mme = None
        self.assignment_miss = None
        self.start_time = None
        self.interval_mota = {10: [], 15: [], 30: []}

    def update(self, detections, states): 
        if self.start_time is None and len(states) > 0:
            self.start_time = states[0, 3]

        current_time = states[0, 3]
        elapsed_time = (current_time - self.start_time)

        # print("Tiempo transcurrido: {} segundos".format(elapsed_time))
        print("detecciones: ")
        print(detections)
        print(states)

        #Inicializo el primer track si no hay ninguno
        if len(self.tracks) == 0:
            for i in range(detections.shape[0]):
                track = Tracks(detections[i], self.trackId, states[i])
                self.trackId += 1
                self.tracks.append(track)

        N = len(self.tracks)
        M = len(detections)
        cost = np.zeros((N, M))

        #Creo la matriz de costos para pasarselo al hungaro
        for i in range(N):
            #Esta diferencia es entre la prediccion de kalman y la medicion
            diff = np.linalg.norm(self.tracks[i].prediction - detections.reshape(-1,2), axis=1)
            # print(self.tracks[i].prediction)
            cost[i, :] = diff

        cost *= 0.1  
        row, col = linear_sum_assignment(cost) 

        #Esta lista contiene todas las asignaciones hechas por el hungaro a cada prediccion hecha por kalman
        assignment = [-1] * N   
        for i in range(len(row)):
            assignment[row[i]] = col[i]

        print("Lista de asignaciones de las detecciones actuales a tracks en este frame: ")
        print(assignment)

        un_assigned_tracks = []
        fp = 0
        miss = 0
        mme = 0
        gt = 0
        dit = 0
        ct = 0

        for i in range(len(assignment)):
            if assignment[i] != -1:
                if (cost[i][assignment[i]] > self.dist_threshold):  
                    #Una asignacion mal hecha, separa la medicion de la hipotesis
                    assignment[i] = -1
                    #Esta medicion sera emparejada despues, por lo cual deja una hipotesis sin pareja
                    un_assigned_tracks.append(i)
                    #Dado que tengo una hipotesis sin objeto asociado, tengo un falso positivo
                    fp += 1  
                else:
                    self.tracks[i].skipped_frames = 0

        del_tracks = []

        for i in range(len(self.tracks)):
            if self.tracks[i].skipped_frames > self.max_frame_skipped:
                del_tracks.append(i)

        for i in sorted(del_tracks, reverse=True):
            del self.tracks[i]
            del assignment[i]

        for i in range(len(detections)):
            if i not in assignment:
                print("Creando un nuevo track: ")
                track = Tracks(detections[i], self.trackId, states[i])
                self.trackId += 1
                self.tracks.append(track) 
                

        # for i in assignment:
        #     if i != -1:
        #         distance = np.linalg.norm(self.tracks[assignment.index(i)].prediction - detections[assignment[i]].reshape(-1, 2))
        #         dit += distance
        #         ct += 1
        #         self.MOTP_errors['dmax'].append(distance)
                
#         distance = np.linalg.norm(self.tracks[assignment.index(i)].prediction - detections[assignment[i]].reshape(-1, 2))
# 			[object_track_ROS-5] IndexError: list index out of range




        #Añade la deteccion al track, corrige y actualiza el estado del track, ademas de reiniciar el contador de frames saltados
        for i in range(len(assignment)):
            if assignment[i] != -1:
                self.tracks[i].skipped_frames = 0
                self.tracks[i].predict(detections[assignment[i]])
                self.tracks[i].correction(states[assignment[i]]) 
            self.tracks[i].trace.append(self.tracks[i].prediction)
            self.tracks[i].trace_state.append(self.tracks[i].state_correction)

        #Seccion para encontrar a que track pertenecia la deteccion segun la distancia. (Esto solo es para el MOTA)
        N2 = len(self.tracks)
        M2 = len(detections)
        cost2 = []
        tracks_with_data = []  

        #Extraigo los tracks que tengan datos para poder comparar. Esto es para evitar errores con los tracks nuevos.
        for i in range(N2):
            if self.tracks[i].trace:
                tracks_with_data.append(i)

        #Calculo la distancia entre cada deteccion y el ultimo punto de cada track.
        for i in tracks_with_data:
            diff2 = np.linalg.norm(self.tracks[i].trace[-1] - detections.reshape(-1, 2), axis=1)
            cost2.append(diff2)

        #De igual forma que antes, se realizan las asociaciones con el hungaro.
        cost2 = np.array(cost2) * 0.1  
        print("Matriz de costo 2: ")
        print(cost2)

        if len(cost2) > 0:
            #Algoritmo hungaro para asociar tracks con detecciones.
            row2, col2 = linear_sum_assignment(cost2)
            print(row2, col2)

            assignment2 = [-1] * len(tracks_with_data)
            for i in range(len(row2)):
                assignment2[row2[i]] = col2[i]

            print("Asignacion de las detecciones actuales a un track en frames anteriores: ")
            print(assignment2)

            for j in range(len(assignment)):
                if assignment2[j] != -1 and (assignment2[j] in assignment):
                    index = assignment.index(assignment2[j])
                    #Si la asignacion actual realizada por kalman y el hungaro, no corresponde a la asignacion anterior calculada por distancia
                    if index != j:
                        #Significa que hubo un cambio de color
                        mme += 1
                elif (assignment2[j] not in assignment):
                    mme += 1

        #Dado que sabemos el numero real de personas en el experimento, todo track extra sera un falso positivo.
        if len(assignment) > self.gt_count:
            for i in range(2, len(assignment)):
                print("Indice del ultimo if: " + str(i))
                if assignment[i] != -1:
                    fp += 1

        #Conteo de miss error. Si en un frame, un track ya creado no es actualizado (faltan objetos)(mediciones < tracks)
        #Eso significa que el objeto del track respectivo se ha "perdido de vista" por el tracker.
        for i in assignment:
            if i == -1:
                miss +=1

        gt += self.gt_count
        

        self.MOTA_errors['fp'] += fp
        self.MOTA_errors['miss'] += miss
        self.MOTA_errors['mme'] += mme
        self.MOTA_errors['gt'] += gt
        self.MOTP_errors['dit'] += dit
        self.MOTP_errors['ct'] += ct

    def calculate_MOTA(self):
        FP = self.MOTA_errors['fp']
        misses = self.MOTA_errors['miss']
        MME = self.MOTA_errors['mme']
        gt_count = self.MOTA_errors['gt']

        if gt_count != 0:
            MOTA = (1 - ((FP + misses + MME) / gt_count)) *100
            return MOTA
    
    def calculate_MOTP(self):
        d = self.MOTP_errors['dit']
        ct = self.MOTP_errors['ct']

        if ct != 0:
            MOTP = (d/ct)/100
            MOTPNorm = (1.0 - (MOTP/max(self.MOTP_errors['dmax']))) * 100
            return MOTP, MOTPNorm
    
    def printer(self, str):
        print("testline :", str)
        for i in range(len(self.tracks)):
            print(self.tracks[i].trace)
        print()