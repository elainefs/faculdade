"""
Construir algoritmo interativo para calcular Fibonacci.
"""

import time

def fib_iterativo(n):
    atual = 0
    ultimo = 0
    penultimo = 1

    for i in range(1, n + 1):
        atual = ultimo + penultimo
        penultimo = ultimo
        ultimo = atual

    return atual

def medir_tempo_iterativo(n):
    tempo_inicial = time.time()
    resultado = fib_iterativo(n)
    tempo_final = time.time()
    print(f"Fibonacci (Iterativo) de {n}: {resultado}")
    print(f"Tempo de execução: {tempo_final - tempo_inicial:.6f} segundos")

n = int(input("Digite n: ")) 

medir_tempo_iterativo(n)