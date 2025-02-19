"""
Grafo.
Implementar algoritmo que representa a lista de adjacência abaixo:
0: 0 2
1: 3 3
2: 6
3: 7
4: 
5:
6: 0 4 2
7
8: 5
"""

class No:
    def __init__(self, w):
        self.w = w
        self.proximo = None

class Grafo:
    def __init__(self, V):
        self.V = V
        self.A = 0
        self.adj = [None] * V

    def add_vertice(self, v, w):
        novo_no = No(w)
        novo_no.next = self.adj[v]
        self.adj[v] = novo_no
        self.A += 1

    def print_grafo(self):
        for v in range(self.V):
            print(f"Vértice {v}:")
            temp = self.adj[v]
            while temp:
                print(temp.w, end=" ")
                temp = temp.next
            print()

V = 9
grafo = Grafo(V)

grafo.add_vertice(0, 2)
grafo.add_vertice(0, 0)
grafo.add_vertice(1, 3)
grafo.add_vertice(1, 3)
grafo.add_vertice(2, 6)
grafo.add_vertice(3, 7)
grafo.add_vertice(6, 2)
grafo.add_vertice(6, 4)
grafo.add_vertice(6, 0)
grafo.add_vertice(8, 5)

grafo.print_grafo()