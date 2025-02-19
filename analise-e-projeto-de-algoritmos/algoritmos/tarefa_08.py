"""
Escrever um algoritmo recursivo que calcule a soma dos elementos de um vetor A[1..n]
para n = 50 e n = 100 e que exiba os resultados parciais dos cálculos lado a lado.
Implementar a soma da esquerda para a direita e da direta para a esquerda.
"""

def soma_esq_dir(k, n, A, resultados_parciais):
    if k > n:
        return 0
    else:
        soma_parcial = A[k] + soma_esq_dir(k+1, n, A, resultados_parciais)
        resultados_parciais.append(soma_parcial)
        return soma_parcial

def soma_dir_esq(k, n, A, resultados_parciais):
    if k > n:
        return 0
    else:
        soma_parcial = A[n] + soma_dir_esq(k, n-1, A, resultados_parciais)
        resultados_parciais.append(soma_parcial)
        return soma_parcial

def calcular_somas(n):
    A = list(range(1, n + 1))
    resultados_parciais_esq = []
    resultados_parciais_dir = []

    soma_esq_dir(0, n - 1, A, resultados_parciais_esq)
    soma_dir_esq(0, n - 1, A, resultados_parciais_dir)

    print(f"\nResultados parciais dos cálculos para n = {n}:")
    print(f"{'Índice':<10}{'Valor Adicionado':<20}{'Soma Parcial (esq-dir)':<20}\t{'Soma Parcial (dir-esq)':<20}")
    for i in range(n):
        print(f"{i + 1:<10}{A[i]:<20}{resultados_parciais_esq[i]:<20}\t{resultados_parciais_dir[n-i-1]:<20}")

calcular_somas(50)
calcular_somas(100)
