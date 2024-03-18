"""
Scripts criados originalmente no Google Colab
"""

## Média

## Exercício 01

# Importando a biblioteca statistics
import statistics

# Definindo a lista de tempos de resposta
tempos_resposta = [100, 200, 150, 300, 250]

# Calculando a média dos tempos de resposta
media_tempo_resposta = statistics.mean(tempos_resposta)

# Imprimindo a média
print("Média do tempo de resposta:", media_tempo_resposta, "ms")

# Exercicio 02

# Importando a biblioteca statistics
import statistics

# Definindo a lista de tempos de resposta
vendas_diarias = [120, 150, 180, 200, 170]

# Calculando a média dos tempos de resposta
media_vendas_diarias = statistics.mean(vendas_diarias)

# Imprimindo a média
print("Média de vendas diárias:", media_vendas_diarias)

## Mediana

## Exercício 01


def calcular_mediana(lista):
  # Ordenando a lista em ordem crescente
  lista.sort()

  # Se a lista tiver um número ímpar de elementos, a mediana é o elemento central
  if len(lista) % 2 == 1:
    return lista[len(lista) // 2]

  # Se a lista tiver um número par de elementos, a mediana é a média dos dois elementos centrais
  else:
    meio1 = len(lista) // 2
    meio2 = meio1 - 1
    return (lista[meio1] + lista[meio2]) / 2

# Definindo a lista de números de páginas visitadas
numeros_paginas = [3, 5, 2, 8, 7, 6]

# Calculando a mediana
mediana_paginas = calcular_mediana(numeros_paginas)

# Imprimindo a mediana
print("Mediana do número de páginas:", mediana_paginas)

## Exercício 02

def calcular_mediana(lista):
  # Ordenando a lista em ordem crescente
  lista.sort()

  # Se a lista tiver um número ímpar de elementos, a mediana é o elemento central
  if len(lista) % 2 == 1:
    return lista[len(lista) // 2]

  # Se a lista tiver um número par de elementos, a mediana é a média dos dois elementos centrais
  else:
    meio1 = len(lista) // 2
    meio2 = meio1 - 1
    return (lista[meio1] + lista[meio2]) / 2

# Definindo a lista de números de páginas visitadas
numeros_pontuacoes = [85, 90, 95, 80, 75, 100]

# Calculando a mediana
mediana_pontuacoes = calcular_mediana(numeros_pontuacoes)

# Imprimindo a mediana
print("Mediana do número de pontuações:", mediana_pontuacoes)

## Moda

## Exercício 01

from collections import Counter

# Definindo a lista de categorias
categorias = ["Eletrônicos", "Livros", "Roupas", "Eletrônicos", "Roupas"]

# Criando um dicionário para contar as frequências das categorias
contagem_categorias = Counter(categorias)

# Encontrando a moda das categorias
moda_categorias = contagem_categorias.most_common(1)[0][0]

# Imprimindo a moda
print("Moda das categorias:", moda_categorias)

## Exercício 02

from collections import Counter

# Definindo a lista de versões
versoes = ["1.0", "2.0", "1.0", "3.0", "2.0", "1.0"]

# Criando um dicionário para contar as frequências das versões
contagem_versoes = Counter(versoes)

# Encontrando a moda das versões
moda_versoes = contagem_versoes.most_common(1)[0][0]

# Imprimindo a moda
print("Moda das versões:", moda_versoes)

## Variância

## Exercício 01

import statistics

# Definindo a lista de tempos
tempos = [2, 4, 6, 8, 10]

# Calculando a variância
variancia_tempos = statistics.variance(tempos)

# Imprimindo a variância
print("Variância do tempo:", variancia_tempos)

## Exercício 02

import statistics

# Definindo a lista de temperaturas
temperaturas = [22, 24, 26, 23, 25, 27, 28]

# Calculando a variância
variancia_temperaturas = statistics.variance(temperaturas)

# Imprimindo a variância
print("Variância da temperatura:", variancia_temperaturas)

## Desvio Padrão

## Exercício 01

import statistics

# Definindo a lista de dados
dados = [1.5, 2.0, 2.5, 3.0, 1.0]

# Calculando o desvio padrão
desvio_padrao_dados = statistics.stdev(dados)

# Imprimindo o desvio padrão
print("Desvio padrão da quantidade de dados:", desvio_padrao_dados)

## Exercício 02

import statistics

# Definindo a lista de vendas
vendas = [100, 150, 200, 250, 300]

# Calculando o desvio padrão
desvio_padrao_vendas = statistics.stdev(vendas)

# Imprimindo o desvio padrão
print("Desvio padrão das vendas:", desvio_padrao_vendas)

## Amplitude

## Exercício 01

# Definindo a lista de valores
velocidades = [50, 60, 70, 80, 90]

# Cálculo da amplitude
amplitude = max(velocidades) - min(velocidades)

# Impressão da amplitude
print("Amplitude da velocidade de download:", amplitude, "Mbps")

## Exercício 02

# Definindo a lista de alturas
alturas = [160, 165, 170, 175, 180]

# Cálculo da amplitude
amplitude = max(alturas) - min(alturas)

# Impressão da amplitude
print("Amplitude das alturas:", amplitude, "cm")
