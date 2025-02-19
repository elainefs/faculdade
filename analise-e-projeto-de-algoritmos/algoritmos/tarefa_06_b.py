"""
Implementar um algoritmo usando a formula matemática direta que realiza a soma dos quadrados de um número inteiro
positivo e devolve outro inteiro positivo.
"""

import time

def soma_quadrados_b(n):
  x = (n * (n + 1) * (2 * n + 1)) // 6
  return x

n = int(input("Digite um número inteiro positivo: "))

if n > 0:
  inicio_b = time.time()
  resultado_b = soma_quadrados_b(n)
  fim_b = time.time()
  tempo_b = fim_b - inicio_b
    
  print(f"Soma dos quadrados (método B): {resultado_b}")
  print(f"Tempo de execução do método B: {tempo_b:.6f} segundos")
else:
  print("O número deve ser um inteiro positivo.")