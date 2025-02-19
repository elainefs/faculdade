"""
Escrever um algoritmo recursivo que calcule a soma dos elementos de um vetor A[1..n]
para n = 50 e n = 100 e que exiba os resultados parciais dos cálculos lado a lado.
"""

def soma(n, A, resultados_parciais):
    if n == 0:
        return 0
    else:
        soma_parcial = soma(n - 1, A, resultados_parciais) + A[n - 1]
        resultados_parciais.append(soma_parcial)
        return soma_parcial

def executar_calculo(n):
    A = list(range(1, n + 1))  
    
    resultados_parciais = []

    resultado = soma(n, A, resultados_parciais)

    print(f"\nResultados parciais dos cálculos para n = {n}:")
    print(f"{'Índice':<10}{'Valor Adicionado':<20}{'Soma Parcial':<15}")
    for i in range(n):
        print(f"{i + 1:<10}{A[i]:<20}{resultados_parciais[i]:<15}")
    
    print(f"\nA soma dos elementos do vetor para n = {n} é: {resultado}")

executar_calculo(50)
executar_calculo(100)
