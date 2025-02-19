"""
Algoritmo iterativo para verificar se um dado inteiro x é elemento do vetor A[1…n]. Deve devolver SIM se x está em
A[1…n] e devolve NÃO em caso contrário.
"""

import time 

def decide_i(A, n, x):
    i = 1
    while i <= n and A[i - 1] != x:
        print(f'Comparando A[{i}] = {A[i - 1]} com x = {x}')
        i += 1
    if i > n:
        return "NÃO"
    else:
        return "SIM"
    
def exc_decide_i(n, x):
    A = list(range(1, n + 1))
    tempo_inicial = time.time()
    resultado_i = decide_i(A, len(A), x)
    tempo_final = time.time()
    print(f'Tempo de execução (Iterativo): {tempo_final - tempo_inicial}')
    print(f'{resultado_i}')

print('Decisão Iterativa: ')
exc_decide_i(10, 10)
exc_decide_i(100, 100)