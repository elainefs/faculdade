"""
Escrever e explicar um programa de computador para achar o produto de menor custo
entre n matrizes, usando programação dinâmica.
"""

import sys

Maxn = 10

def ordem_matrix(b):
    n = len(b) - 1
    m = [[0] * Maxn for _ in range(Maxn)]
    s = [[0] * Maxn for _ in range(Maxn)]

    for i in range(n):
        m[i][i] = 0
    for h in range(1, n):  
        for i in range(1, n - h + 1):
            j = i + h
            m[i - 1][j - 1] = sys.maxsize 
            
            for k in range(i, j):
                temp = m[i - 1][k - 1] + m[k][j - 1] + b[i - 1] * b[k] * b[j]
                if temp < m[i - 1][j - 1]:
                    m[i - 1][j - 1] = temp
                    s[i - 1][j - 1] = k 

    return m, s

def print_parenteses(s, i, j):
    if i == j:
        print(f"M{i + 1}", end="")
    else:
        print("(", end="")
        print_parenteses(s, i, s[i][j] - 1) 
        print_parenteses(s, s[i][j], j)  
        print(")", end="")

def multiplicacao_matrix():
    b = [0] * (Maxn + 1)

    n = int(input("Número de matrizes n: "))
    
    print("Dimensões das matrizes:")
    for i in range(n + 1):
        b[i] = int(input())

    m, s = ordem_matrix(b)

    print(f"Custo mínimo: {m[0][n - 1]}")

    print("Solução ótima: ", end="")
    print_parenteses(s, 0, n - 1)
    print()  

multiplicacao_matrix()