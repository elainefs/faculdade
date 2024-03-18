import math

dados = [100, 150, 200,	250, 300]
media = sum(dados) / len(dados)

soma_quadrados_diff = sum((x - media) ** 2 for x in dados)

desvio_medio = sum(abs(x - media) for x in dados) / len(dados)
desvio_padrao = math.sqrt(soma_quadrados_diff / len(dados))
variancia = soma_quadrados_diff / len(dados)

print(f"O desvio médio dos dados é: {desvio_medio: .2f}")
print(f"A variância dos dados é: {variancia: .2f}")
print(f"O desvio padrão dos dados é: {desvio_padrao: .2f}")