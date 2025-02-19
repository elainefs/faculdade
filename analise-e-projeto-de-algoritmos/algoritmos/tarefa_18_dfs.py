"""
Algoritmo de busca em profundidade
O algoritmo de busca em profundidade visita todos os vértices e todos os arcos do grafo
numa determinada ordem e atribui um número a cada vértice.

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

def dfs(grafo):
    def dfs_recursiva(v):
        nonlocal numero_pre_ordem
        visitados[v] = True
        pre[v] = numero_pre_ordem
        numero_pre_ordem += 1

        for vizinho in grafo[v]:
            if not visitados[vizinho]:
                dfs_recursiva(vizinho)

    n = len(grafo)
    visitados = [False] * n
    pre = [-1] * n
    numero_pre_ordem = 0

    for v in range(n):
        if not visitados[v]:
            dfs_recursiva(v)

    return pre

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

resultado = dfs(grafo1)
print("Ordem de visita Grafo 01:", resultado)

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

resultado = dfs(grafo2)
print("Ordem de visita Grafo 02:", resultado)