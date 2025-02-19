"""
Construir programas para:
-Implementar F(n) com a solução de recorrência.
Requisitos:
Usar n=100 e n=1000, com F(0)=1 e F(0)=10
"""

import time

def recorrencia(n, F0):
    return F0 + (n * (n + 1)) // 2 + n

def medir_tempo(func, *args):
    tempo_inicial = time.time()
    result = func(*args)
    tempo_final = time.time()
    tempo_execucao = tempo_final - tempo_inicial
    return result, tempo_execucao

test_cases = [100, 1000]
initial_values = [1, 10]

for F0 in initial_values:
    for n in test_cases:
        result_closed_form, time_closed_form = medir_tempo(recorrencia, n, F0)

        print(f"F(0) = {F0}, n = {n}")
        print(f"Fechado: F({n}) = {result_closed_form}, Tempo: {time_closed_form:.10f} segundos")
        print("-" * 50)
