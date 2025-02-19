"""
Problema do Caixeiro Viajante. Desenvolver um algoritmo para achar o número de rotas
R(n) para os n de 5, 10 e 15 cidades e determinar o tempo de execução para calcular as
rotas.
"""

import itertools
import time

def caixeiro_viajante(num_cidades):
    cidades_restantes = list(range(1, num_cidades))

    permutacoes = itertools.permutations(cidades_restantes)

    rotas = [[0] + list(rota) + [0] for rota in permutacoes]
    return rotas

num_cidades = int(input("Digite o número de cidades: "))
if num_cidades < 2:
    print("O número de cidades deve ser pelo menos 2.")
else:
    inicio = time.time()
    rotas = caixeiro_viajante(num_cidades)
    fim = time.time()

    print(f"Número de rotas: {len(rotas)}")
    print(f"Tempo de execução: {fim - inicio:.10f} segundos")