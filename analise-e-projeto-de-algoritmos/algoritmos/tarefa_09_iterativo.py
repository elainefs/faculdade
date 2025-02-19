"""
Algoritmo iterativo para n=10 e n=100, com os elementos de A[i]=1:1:n e encontrar o valor do maior elemento de um vetor A[1 .. n] de
inteiros, para n ≥ 1.
"""

import time

def max_i(A, n):
    x = A[1]
    print(f'Inicial: x = {x}')
    
    for i in range(1, n):
        print(f'Comparando x = {x} com A[{i}] = {A[i]}')
        if A[i] > x:
            x = A[i]
            print(f'Novo máximo encontrado: x = {x}')
    return x

def exc_max_i(n):
  A = list(range(1, n + 1))
  tempo_inicial = time.time()
  resultado_i =  max_i(A, n)
  tempo_final = time.time()
  print(f'Tempo de execução (Iterativo): {tempo_final - tempo_inicial} segundos')
  print(f'O maior elemento encontrado: {resultado_i}')

exc_max_i(10)
exc_max_i(100)
