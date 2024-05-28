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
