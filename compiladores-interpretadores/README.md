# Compiladores e Interpretadores

O estudo das linguagens formais tem o objetivo de definir matematicamente as estruturas das linguagens naturais.

As linguagens formais estudam como representar as palavras (léxica), estruturas (sintaxe) e significados (semântica) das sentenças das linguagens.

As linguagens de programação passaram por diversas evoluções, a linguagem de máquina é compreensível para os computadores, mas complexas para os seres humanos, e são chamadas de linguagem de baixo nível.

Por outro lado, as linguagens de alto nível, são mais compreensíveis para os humanos, mas não são compreensíveis para as máquinas, necessitando que sejam compiladas ou interpretadas para uma linguagem de máquina.

Um programa escrito em uma linguagem de alto nível é denominado código-fonte.

A tradução da linguagem de alto nível para a linguagem de máquina, normalmente, é feita em mais de um passo.

O programa que faz essa tradução é denominado **compilador** ou **interpretador**.

Segundo Simão & Prince (2001), as linguagens de programação estão associadas aos tipos de tradutores, que podem ser classificados em:

- Montadores
  - Programas que traduzem um código fonte escrito em assembly em código de máquina. Normalmente mais simples e feito em duas etapas.
- Compiladores
  - Traduzem o código fonte, escrito em uma linguagem de alto nível, em código alvo, linguagem de baixo nível. Mais complexo e executado em várias etapas.
- Interpretadores
  - Fazem o mesmo processo do compilador, mas cada linha do programa é analisado por vez, por todas as fases de tradução, até alcançar o código alvo e já o executa. Exige que o programa seja submetido ao interpretador todas as vezes que necessitarem ser executadas.
- Compiladores híbridos
  - Seguem todos os passos de um compilador, mas não geram o código de máquina, mas sim um código intermediário, esse será executado por uma máquina virtual (interpretador). Possui grande portabilidade, mas os passos em relação ao compilador aumentam, podendo gerar problemas de desempenho.

As principais fases de um compilador são: análise e síntese.

```
+---------------------+
|                     |
|    Programa fonte   |
|                     |
+---------------------|
                      +----------->--------------------------------------+
                                  |                                      |
                                  |       Compilador                     |
                                  |                                      |
                                  |                                      |
                                  |                                      |
                                  |                                      |
                                  | +----------------------------------+ |
                  Erros<------------|  Fase de Análise                 | |
                                  | |  - Léxico                        | |
                                  | |  - Sintático                     | |
                                  | |  - Semântico                     | |
                                  | +----------------------------------+ |
                                  |                                      |
                                  |                                      |
                                  |                                      |
                                  |    Fase de síntese                   |
                                  |    - Geração do código intermediário |
                                  |    - Otimização do código            |
                                  |    - Geração do código alvo          |
                                  |                                      |
                                  |                                      |             Resultado:
                                  |                                      ------------> Programa alvo
                                  +--------------------------------------+
```

- Análise: verifica se o programa foi escrito corretamente, isto é, de acordo com as regras da linguagem. Está relacionado a gramática da linguagem.
- Síntese: gera o código alvo a partir dos resultados obtidos pela fase anterior.

A **análise** é dividida em 3 etapas:

- Léxica: verifica se os nomes das entidades estão corretos
- Sintática: verifica se os comandos estão corretos e a ordem em que aparecem
- Semântica: verifica o contexto, se os valores envolvidos nos comandos estão compatíveis

> A análise léxica lê caracteres de entrada, gera os tokens e os disponibiliza para o analisador sintático, que por sua vez, analisa as estruturas, em seguida aciona a análise semântica para verificar se os elementos presentes na estrutura sintática são compatíveis.

A **síntese** é dividida em 2 etapas:

- Gerenciamento da tabela de símbolos, com alimentação e consulta dessa tabela.
- Geração do código intermediário.
- Otimização do código, realizando transformações no código com o objetivo de melhorar o tempo de execução, o consumo de memória ou o tamanho do código
- Geração do código alvo.

## Notação BNF (Backus-Naur Forms)

A notação BNF é uma meta-linguagem, ou seja, uma linguagem para definir outra linguagem.

A EBNF é uma extensão da BNF para melhorar a clareza e concisão das descrições de sintaxe.

- Os não-terminais consistem em nomes escritos entre `<` e `>`;
- O `::=` ou `:=` é usado para representar "definido como";
- O `|` é usado para indicar alternativa, "ou" lógico;
- Os `[]` indicam uma parte opcional, que pode repetir 0 ou 1 vez;
- As `{}` indicam uma parte que pode repetir 0 ou n vezes;
- Os `()` indicam precedências dentro da regra;
- Os `''` indicam um caractere terminal.

```
<var> ::= ('_' | <letra>){ '_' | <letra> | <digito> }
<letra> ::= 'a' | 'b' | 'c' | ... | 'z'
<digito> ::= '0' | '1' | '2' | ... | '9'
```

- **Token**: é o nome dado à um elemento importante da gramática, como o identificador de variável, tipo, etc.
- **Lexema**: são as instâncias/valores do token.

Ex.: O token é número e o lexema é 40.

- **Scanner**: é o gerador de analisador léxico.
- **Lexer**: é o analisador léxico gerador pelo scanner.
- **Parser**: é o gerador de analisador sintático.
- **Parsing**: é o analisador sintático gerador pelo parser.

Os scanners e os parses compõem o frontend do compilador e estão associados à parte de análise.

A parte de síntese, em que o código alvo é gerado, constitui o backend.
