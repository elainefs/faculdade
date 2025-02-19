"""
Implementar o algoritmo que lista os números primos menores ou iguais ao valor da
entrada.
"""

import time

def lista_primo(n):
    inicio = time.time()
    primos = []

    for i in range(2, n + 1):
        e_primo = True

        j = 2
        while j < i:
            if i % j == 0:
                e_primo = False
                break
            j += 1

        if e_primo:
            primos.append(i)

    fim = time.time()
    tempo_execucao = fim - inicio
    return primos, tempo_execucao

n = int(input("Digite um valor inteiro para n: "))

primos, tempo_execucao = lista_primo(n)
print(f"Números primos menores ou iguais a {n}: {primos}")
print(f"Tempo de execução: {tempo_execucao:.5f}")
