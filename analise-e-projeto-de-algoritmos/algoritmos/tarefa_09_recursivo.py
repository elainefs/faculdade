"""
Algoritmo recursivo para n=10 e n=100, com os elementos de A[i]=1:1:n e encontrar o valor do maior elemento de um vetor A[1 .. n] de
inteiros, para n ≥ 1.
"""

import time

def max_r(A, n):
    if n == 1:
        return A[0]
    
    x = max_r(A, n - 1)
    print(f'Comparando x = {x} com A[{n-1}] = {A[n-1]}')
    
    if x < A[n - 1]:
        print(f'Novo máximo encontrado: A[{n-1}] = {A[n-1]}')
        return A[n - 1]
    else:
        return x

def execute_max_r(n):
    A = list(range(1, n + 1))  
    tempo_inicial = time.time()     
    resultado = max_r(A, n)       
    tempo_final = time.time()       
    print(f'Máximo em A (n={n}): {resultado}')
    print(f'Tempo de execução (recursivo): {tempo_final - tempo_inicial} segundos')

execute_max_r(10)
execute_max_r(100)
