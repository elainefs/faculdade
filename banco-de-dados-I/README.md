# Banco de Dados I

> Outros conceitos sobre banco de dados podem ser vistos nas anotações de [Modelagem de Dados](../modelagem-de-dados/README.md)

> SGDB Utilizado: SQL Server

## Structured Query Language (SQL)

É a linguagem padrão para manipulação de dados em bancos de dados relacionais criada pela IBM.

Possui 5 subconjuntos de operações:

- DML: Linguagem de Manipulação de Dados
  - INSERT, UPDATE, DELETE
- DDL: Linguagem de Definição de Dados
  - CREATE, DROP, ALTER
- DCL: Linguagem de Controle de Dados
  - GRANT, REVOKE
- DTL: Linguagem de Transação de Dados
  - BEGIN TRANSACTION, COMMIT, ROLLBACK
- DQL: Linguagem de Consulta de Dados
  - SELECT

### Funções matemáticas

`ABS(valor)` - retorna o valor absoluto 

`POWER(valor, potencia)` - retorna o valor elevado a potência

`ROUND(valor, n)` - arredonda o valor para n casas decimais

`SQRT(valor)` - retorna a raiz quadrada do valor especificado

`PI()` - valor da constante PI

### Operadores de comparação

`BETWEEN valor-inicial AND valor-final`

`IN lista`

`LIKE padrão`

`IS NULL, IS NOT NULL`

`AND, OR, NOT`

Ex.:

Obter todos os produtos cujo nome começa com 'S':

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE 'S%';
```

Obter todos os produtos cujo nome contem a string 'maria':

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE '%maria%';
```

O `%` é usado para substituir qualquer cadeia de caractere

O `_` é usado para substituir qualquer caractere.

Ex.:

Obter nome que tenha 'f' e 't' e qualquer caractere entre essas letras.

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE '%f_t%';
```

O colchetes `[]` combina uma faixa de caracteres

Ex.: 

Obter qualquer nome que comece com 'C' ou com 'M'

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE '[CM]%';
```

Obter qualquer nome qe comece com os caracteres de 'C' até 'X'

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE '[C-X]%';
```

O circunflexo `^` significa negação

Ex.: 

Obter qualquer nome que comece com 'M' e não tenha 'o' como segunda letra

```sql
SELECT nome 
FROM alunos
WHERE nome LIKE 'M[^o]%';
```

### Operadores de agregação

`SUM`, `AVG`, `MIN`, `MAX` e `COUNT`

```sql
SELECT MAX(idade), MIN(idade), AVG(idade), SUM(idade), COUNT(*) 
FROM alunos;
```