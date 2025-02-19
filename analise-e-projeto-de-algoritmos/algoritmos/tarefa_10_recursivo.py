"""
Algoritmo recursivo para verificar se um dado inteiro x é elemento do vetor A[1…n]. Deve devolver SIM se x está em
A[1…n] e devolve NÃO em caso contrário.
"""

import time 

def decide_r(A, n, x):
    if n == 0:
        return "NÃO"
    print(f'Comparando A[{n}] = {A[n - 1]} com x = {x}')
    if A[n - 1] == x: 
        return "SIM"
    else:
        return decide_r(A, n - 1, x)

def exc_decide_r(n, x):
    A = list(range(1, n + 1))
    tempo_inicial = time.time()
    resultado_r = decide_r(A, len(A), x)
    tempo_final = time.time()
    print(f'Tempo de execução (Recursivo): {tempo_final - tempo_inicial}')
    print(f'{resultado_r}')

print('Decisão Recursiva: ')
exc_decide_r(10, 10)
exc_decide_r(100, 100)