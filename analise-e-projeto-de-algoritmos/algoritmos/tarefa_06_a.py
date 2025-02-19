"""
Implementar um algoritmo interativo que realiza a soma dos quadrados de um número inteiro
positivo e devolve outro inteiro positivo.
"""

import time

def soma_quadrados_a(n):
  x = 0
  for j in range(1, n + 1):
    x += j * j
  return x

n = int(input("Digite um número inteiro positivo: "))

if n > 0:
  inicio_a = time.time()
  resultado_a = soma_quadrados_a(n)
  fim_a = time.time()
  tempo_a = fim_a - inicio_a
      
  print(f"Soma dos quadrados (método A): {resultado_a}")
  print(f"Tempo de execução do método A: {tempo_a:.6f} segundos")
else:
  print("O número deve ser um inteiro positivo.")