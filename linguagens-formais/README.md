# Linguagens Formais

## Linguagem

Uma linguagem é o conjunto finito ou infinito de cadeias que atendem a uma determinada regra.

Uma **Linguagem Formal** possui uma **sintaxe bem definida**, ou seja, dada uma sentença, é possível sempre saber se ela pertence ou não a uma linguagem. Além disso, possui uma **semântica precisa**, de modo que não contenha sentenças sem significado ou ambíguas.

As palavras, cadeias ou sentenças, são sequências finita de símbolos, do alfabeto, justapostos (concatenados).

## Análise Léxica e Sintática

A análise léxica avalia se uma palavra pertence a uma linguagem e se está bem formada.

A análise Sintática avalia se a forma de uma estrutura está correta.

## Áreas de aplicação das linguagem formais

- Inteligência Artificial
- Compiladores e Interpretadores
- Lógica para resolução de problemas
- Processamento de linguagens naturais

## Métodos de representação de linguagens

- Enumerações
- Gramáticas
- Reconhecedores

## Expressões regulares

Uma expressão regular é uma representação matemática para identificar conjuntos de cadeias.

| ER           | Linguagem Reconhecida                                                                       |
| ------------ | ------------------------------------------------------------------------------------------- |
| `ε`          | Linguagem formada pela palavra vazia ε                                                      |
| `aa`         | Linguagem formada pela palavra aa                                                           |
| `a+`         | Linguagem formada por no mínimo um a. Ex: a , aa, aaa... (um ou mais)                       |
| `a*`         | Linguagem formada por zero ou mais a’s. Ex: ε, a, aa, aaa... (zero ou mais)                 |
| `a+ (b + c)` | Linguagem formada por no mínimo um a e terminada por b ou c. Ex: ab, ac, aac, aaaab, ...    |
| `(a \| b*)`  | Linguagem formada por a ou por zero ou vários b’s. Ex: a, ε, b, bb, bbb...                  |
| `(a U b)+`   | Linguagem formada por no mínimo um a ou b. Ex: a, b, ab, ba, aaa, bbb, abb, baa, abab, ...  |
| `b (a + b)*` | Linguagem que começa com b, seguida por um conjunto de a ou b. Ex: b, bbbb, baba, bbba, ... |

## Autômatos

São como máquinas abstratas, dotadas de um conjunto finito de regras e instruções, capazes de analisar sequências de símbolos e determinar se pertencem ou não a uma linguagem específica.

- Estados: Representam as diferentes configurações em que o autômato pode se encontrar durante a análise de uma sequência de símbolos.
- Alfabeto: Conjunto finito de símbolos que o autômato pode ler e processar.
- Função de Transição: Define as regras que determinam a mudança de estado do autômato a cada símbolo lido.
- Estado Inicial: O ponto de partida do autômato na análise de uma sequência.
- Estados Finais: Conjunto de estados que indicam se a sequência analisada pertence ou não à linguagem.

### Tipos

- Autômatos Finitos Determinísticos (AFD):
  - Possuem uma única regra de transição possível para cada estado e símbolo. São eficientes para reconhecer linguagens regulares, como expressões regulares utilizadas em ferramentas de busca e validação de dados.
- Autômatos Finitos Não Determinísticos (AFN):
  - Permitem múltiplas regras de transição para um mesmo estado e símbolo, agregando mais flexibilidade. Reconhecem linguagens mais complexas que os AFDs, como linguagens context-free, utilizadas em compiladores e processadores de linguagem natural.
- Máquinas de Turing:
  - Consideradas o modelo computacional mais poderoso, são capazes de reconhecer qualquer linguagem formal, mesmo as mais complexas. Funcionam com uma fita infinita, permitindo que a máquina armazene e acesse informações durante a computação.
  - Constituição: Fita (entrada, saída e memória de trabalho), Unidade de Controle (reflete o estado corrente da máquina) e Programa, Função Programa ou Função de Transição (define o estado da máquina)

### Hierarquia de Chomsky

Classifica as linguagens formais de acordo com o poder computacional necessário para reconhecê-las, estabelecendo uma relação entre os tipos de autômatos e as classes de linguagens:

- Linguagens Regulares: Reconhecidas por AFDs.
- Linguagens Context-Free: Reconhecidas por AFNs.
- Linguagens Context-Sensitive: Reconhecidas por gramáticas context-sensitive.
- Linguagens Recursivamente Enumeráveis: Reconhecidas por máquinas de Turing.
- Linguagens Recursivas: Subconjunto das linguagens recursivamente enumeráveis que podem ser decididas por máquinas de Turing.
