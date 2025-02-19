"""
Calcule o menor caminho da cidade a até a c, utilizando um algoritmo guloso.
"""

import heapq

def dijkstra(grafo, inicio, fim):
    distancias = {cidade: float('inf') for cidade in grafo}
    distancias[inicio] = 0
    fila_prioridade = [(0, inicio)]
    nos_anteriores = {cidade: None for cidade in grafo}

    while fila_prioridade:
        distancia_atual, cidade_atual = heapq.heappop(fila_prioridade)

        if cidade_atual == fim:
            break

        if distancia_atual > distancias[cidade_atual]:
            continue

        for vizinho, peso in grafo[cidade_atual].items():
            distancia = distancia_atual + peso

            if distancia < distancias[vizinho]:
                distancias[vizinho] = distancia
                nos_anteriores[vizinho] = cidade_atual
                heapq.heappush(fila_prioridade, (distancia, vizinho))

    caminho = []
    nodo_atual = fim
    while nodo_atual is not None:
        caminho.append(nodo_atual)
        nodo_atual = nos_anteriores[nodo_atual]
    caminho.reverse()

    return caminho, distancias[fim]

grafo = {
    'a': {'b': 16, 'f': 21, 'e': 9},
    'b': {'c': 5, 'f': 11, 'd': 6},
    'c': {'d': 10},
    'd': {'e': 18, 'f': 14},
    'e': {'f': 33},
    'f': {}
}

cidade_inicial = 'a'
cidade_final = 'c'
caminho, peso_total = dijkstra(grafo, cidade_inicial, cidade_final)

print(f"Menor caminho de {cidade_inicial} até {cidade_final}: {' -> '.join(caminho)} com peso total: {peso_total}")
