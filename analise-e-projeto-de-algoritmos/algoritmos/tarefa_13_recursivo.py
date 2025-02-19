"""
Construir algoritmo recursivo para calcular Fibonacci.
"""

import time

def fib_recursivo(n):
    if n < 2:
        return n
    else:
        return fib_recursivo(n - 1) + fib_recursivo(n - 2)
    
def medir_tempo_recursivo(n):
    tempo_inicial = time.time()
    resultado = fib_recursivo(n)
    tempo_final = time.time()
    print(f"Fibonacci (Recursivo) de {n}: {resultado}")
    print(f"Tempo de execução: {tempo_final - tempo_inicial:.6f} segundos")

n = int(input("Digite n: ")) 

medir_tempo_recursivo(n)