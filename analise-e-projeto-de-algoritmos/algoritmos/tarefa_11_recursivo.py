"""
Construir programas para:
-Implementar F(n) recursivo
Requisitos:
Usar n=100 e n=1000, com F(0)=1 e F(0)=10
"""

import time

def recursivo(n, F0):
    if n == 0:
        return F0
    return recursivo(n - 1, F0) + n + 1

def medir_tempo(func, *args):
    tempo_inicial = time.time()
    result = func(*args)
    tempo_final = time.time()
    tempo_execucao = tempo_final - tempo_inicial
    return result, tempo_execucao

test_cases = [100, 1000]
valores_iniciais = [1, 10]

for F0 in valores_iniciais:
    for n in test_cases:
        resultado_recursivo, tempo_recursivo = medir_tempo(recursivo, n, F0)

        print(f"F(0) = {F0}, n = {n}")
        print(f"Recursivo: F({n}) = {resultado_recursivo}, Tempo: {tempo_recursivo:.10f} segundos")
        print("-" * 50)
