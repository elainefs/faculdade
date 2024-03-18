"""
Scripts criados originalmente no Google Colab
"""

## Preferências dos alunos em relação ao gosto musical

# Importar bibliotecas
import pandas as pd

# Criar dicionário com os dados
dados = {
    "Tipo de música": ["Pop", "Rock", "Hip-Hop", "Eletrônica", "Sertanejo"],
    "Frequência absoluta": [35, 20, 15, 10, 20]
}

# Criar DataFrame
df = pd.DataFrame(dados)

# Calcular frequência relativa
df["Frequência relativa"] = df["Frequência absoluta"] / df["Frequência absoluta"].sum()

# Calcular frequência relativa percentual
df["Frequência relativa percentual"] = df["Frequência relativa"] * 100

# Calcular frequência acumulada
df["Frequência acumulada"] = df["Frequência absoluta"].cumsum()

# Mostrar DataFrame
print(df.to_string())

# Total de alunos
total_alunos = df["Frequência absoluta"].sum()

# Exibir total de alunos
print(f"Total de alunos: {total_alunos}")

## Preferência dos alunos por gênero literário

# Importar bibliotecas
import pandas as pd

# Criar dicionário com os dados
dados = {
    "Gênero": ["Romance", "Ficção científica", "Mistério", "Fantasia", "Não gosto de ler"],
    "Frequência absoluta": [25, 15, 20, 30, 10]
}

# Criar DataFrame
df = pd.DataFrame(dados)

# Calcular frequência relativa
df["Frequência relativa"] = df["Frequência absoluta"] / df["Frequência absoluta"].sum()

# Calcular frequência relativa percentual
df["Frequência relativa percentual"] = df["Frequência relativa"] * 100

# Calcular frequência acumulada
df["Frequência acumulada"] = df["Frequência absoluta"].cumsum()

# Mostrar DataFrame
print(df.to_string())

# Total de pessoas
total_pessoas = df["Frequência absoluta"].sum()

# Exibir total de pessoas
print(f"Total de pessoas: {total_pessoas}")

## Altura média dos pacientes da clínica

# Importar bibliotecas
import pandas as pd

# Criar dicionário com os dados
dados = {
    "LI": [161, 166, 171, 176],
    "LS": [166, 171, 176, 181],
    "Frequência": [4, 6, 2, 4]
}

# Criar DataFrame
df = pd.DataFrame(dados)

# Calcular ponto médio de cada classe
df["Ponto médio"] = (df["LS"] + df["LI"]) /2

# Multiplicar ponto médio pela frequência
df["Frequência x Ponto médio"] = df["Frequência"] * df["Ponto médio"]

# Calcular soma de frequências x ponto médio
soma_frequencia_x_ponto_medio = df["Frequência x Ponto médio"].sum()

# Calcular soma de frequências
soma_frequencia = df["Frequência"].sum()

# Calcular média
media = soma_frequencia_x_ponto_medio / soma_frequencia

# Exibir resultado
print(f"Média de altura: {media:.2f} cm")

## Acesso a Sites

# Importar bibliotecas
import pandas as pd

# Cria dicionário com os dados
dados = {
    "Seg": [80, 100, 30, 40],
    "Ter": [60, 50, 100, 60],
    "Qua": [40, 60, 70, 30],
    "Qui": [100, 20, 40, 40],
    "Sex": [50, 80, 60, 80]
}

# Criar DataFrame
df = pd.DataFrame(dados)

# Calcular frequência aboluta dos acessos na segunda
soma_dos_acessos_seg = df["Seg"].sum()
soma_dos_acessos_ter = df["Ter"].sum()
soma_dos_acessos_qua = df["Qua"].sum()
soma_dos_acessos_qui = df["Qui"].sum()
soma_dos_acessos_sex = df["Sex"].sum()

# Exibir resultados
print(f"Seg:", soma_dos_acessos_seg)
print(f"Ter:", soma_dos_acessos_ter)
print(f"Qua:", soma_dos_acessos_qua)
print(f"Qui:", soma_dos_acessos_qui)
print(f"Sex:", soma_dos_acessos_sex)

## Estaturas alunos

import pandas as pd

# Criar dicionário com os dados
dados = {
    "LI": [1.5, 1.53, 1.56, 1.59, 1.62, 1.65, 1.68, 1.71],
    "LS": [1.53, 1.56, 1.59, 1.62, 1.65, 1.68, 1.71, 1.73],
    "Frequência": [3, 6, 6, 10, 7, 4, 4, 2]
}

# Criar DataFrame
df = pd.DataFrame(dados)

# Média ponderada
media = ((df["LI"] + df["LS"]) / 2 * df["Frequência"]).sum() / df["Frequência"].sum()

# Mediana
mediana = df["LI"].median()

# Moda
moda = df['LI'].mode().iloc[0]

# Frequência absoluta
frequencia_absoluta = df["Frequência"]

# Frequência relativa
df["Frequencia Relativa"] = df["Frequência"] / df["Frequência"].sum()

# Frequência relativa percentual
df["Frequencia Relativa Percentual"] = frequencia_relativa * 100

# Frequência acumulada
df["frequencia_acumulada"] = df["Frequência"].cumsum()

# Exibir resultados

print(df.to_string(index=False))
print(f"Média: {media:.2f}")
print("Mediana:", mediana)
print("Moda:", moda)
