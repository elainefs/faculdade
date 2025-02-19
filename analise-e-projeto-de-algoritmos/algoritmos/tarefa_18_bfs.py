"""
Algoritmo de busca em largura
A busca em largura começa por um vértice especificado e depois visita todos os
vizinhos do vértice especificado, depois todos os vizinhos dos vizinhos, e assim por
diante.

a) Grafo dado pelos arcos 0-1 1-2 1-3 3-4 3-5 1-6 0-7 7-8 7-9 8-6.
b) Grafo dado pela lista de adjacência a seguir:
0: 1 4
1: 2 5
2: 3
3: 7
4: 8
5: 4
6: 5 10 2
7: 11 6
8: 9
9: 5 8
10: 9
11: 10
"""

from collections import deque

def bfs(grafo, inicio):
    visitados = {}
    pai = {}
    fila = deque([inicio])

    visitados[inicio] = True
    pai[inicio] = None

    while fila:
        vertice = fila.popleft()
        print(f"Visitando vértice: {vertice}")

        for vizinho in grafo[vertice]:
            if vizinho not in visitados:
                visitados[vizinho] = True
                pai[vizinho] = vertice
                fila.append(vizinho)
                print(f"  Visitando vizinho: {vizinho}")

    return pai

grafo1 = {
    0: [1, 7],
    1: [2, 3, 6],
    2: [],
    3: [4, 5],
    4: [],
    5: [],
    6: [],
    7: [8, 9],
    8: [6],
    9: []
}

print("Grafo 01")
pai = bfs(grafo1, 0)

grafo2 = {
    0: [1, 4],
    1: [2, 5],
    2: [3],
    3: [7],
    4: [8],
    5: [4],
    6: [5, 10, 2],
    7: [11, 6],
    8: [9],
    9: [5, 8],
    10: [9],
    11: [10]
}

print("Grafo 02")
pai = bfs(grafo2, 0)