#Pode otimizar, assim que a distancia dentro do for maior que a maior de fora ja pula uma iteracao
#Mas deixei assim para ficar equivalente ao código em C++

import numpy as np
import time

inicio = time.time()
matriz = [[0.0, 1418.18, 2257.78, 1999.43, 1527.34, 2146.76, 1583.07, 4.69], [1428.26, 0.0, 1396.6, 1760.27, 1535.65, 2194.93, 1343.9, 1432.95], [2232.85, 1317.03, 0.0, 943.18, 1660.95, 2930.88, 1048.83, 2237.53], [1935.89, 1850.79, 1243.16, 0.0, 722.31, 1992.24, 689.71, 1940.58], [1585.47, 1514.45, 1686.92, 778.61, 0.0, 1327.6, 765.9, 1590.16], [2644.37, 2569.23, 3583.8, 2658.34, 1802.44, 0.0, 2645.62, 2649.05], [1368.0, 1161.08, 1456.39, 969.82, 795.41, 1949.74, 0.0, 1372.69], [52.52, 1413.49, 2253.09, 1994.74, 1522.65, 2142.07, 1578.38, 0.0]]

melhor = []
melhor_distancia = 9999999999999999999999
for i in range(2000000):
    distan = 0
    origem = 0
    caminho = []
    for i in range(len(matriz)):
        aleatorio = np.random.randint(0, len(matriz))
        while (aleatorio in caminho) or (aleatorio == origem):
            aleatorio = np.random.randint(0, len(matriz))
        distan += matriz[origem][aleatorio]
        origem = aleatorio
        caminho.append(origem)

    if distan <= melhor_distancia:
        melhor_distancia = distan
        melhor = caminho

print(melhor_distancia)
print(melhor)
print('tempo: {}' .format(time.time()-inicio))
