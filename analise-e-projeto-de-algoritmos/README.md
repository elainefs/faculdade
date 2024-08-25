# Análise e Projeto de Algoritmos

Algoritmos são o cerne da computação. Eles são uma sequência de passos bem definidos, não ambíguos e finitos que quando executados realizam uma tarefa específica. Eles devem iniciar, processar por um determinado tempo e finalizar.

## Complexidade de Algoritmos

A complexidade de um algoritmo estuda e define quanto eficiente é um algoritmo em relação ao número de operações necessários para finalizar a tarefa.

Computadores diferentes, mesmo que tenham hardwares idênticos, podem levar tempos diferentes para realizar uma mesma tarefa. Portanto, avaliar o desempenho de um algoritmo apenas com base no tempo de execução é ineficiente.

O cenário utilizado para representar um algoritmo é o de pior caso. Mas o mais comum é arredondar para uma complexidade mais comum, devido a análise assintótica[^1].

[^1]: Forma de julgar quão eficiente é um algoritmo, independente dos recursos utilizados. É uma avaliação de tempo de execução de um algoritmo com um número grande de elementos e entrada.

## Custo Computacional

A função de complexidade de cada algoritmo é definida pelo custo computacional e para isso deve-se considerar o modelo de máquina.

## Modelos de Máquinas

RAM: Máquina de Acesso Aleatório

Tem o objetivo de encontrar um meio de expressar de forma simples um algoritmo para que seja fácil de escrever e manipular e que mostre características importantes de requisitos de recursos de um algoritmo e que suprima detalhes tediosos.

Características:

- Instruções executadas uma após a outra, sem paralelismo
- Operações comuns: operações lógicas e aritméticas, manipulação de dados, condicionais, sub-rotinas e chamadas de retorno
- Cada instrução demora um período constante para executar
- Dados podem ser inteiros ou ponto flutuante
- Hierarquia de memórias é ignorada (cache, memória virtual, etc)

Elementos do modelo:

- Um único processador
- Memória

Um sistema de regras de manipulação de dados é dito Turing-Completo, ou computacionalmente universal, se pode ser usado para simular qualquer Máquina de Turing.

**Equivalência de Turing:** dois computadores, P e Q, são chamados equivalentes se P pode simular Q e Q pode simular P.

**Tese de Church-Turing:** qualquer função cujos valores podem ser calculados por um algoritmo pode ser calculado por uma máquina de Turing. Se qualquer computador do mundo real pode simular uma máquina de Turing, é Turing equivalente a uma máquina de Turing. Qualquer linguagem de programação de propósito geral é suficiente para expressar qualquer algoritmo.

O **tamanho da entrada** depende do estudo que está sendo realizado.

O **tempo de execução** de um algoritmo é a soma do tempo de execução de cada instrução. É o tempo necessário para executar as instruções (passos) para uma determinada entrada.

### Máquina de Turing

- Alan Turing, 1936
- Possui 3 componentes:
  - Fita infinita (memória infinita e irrestrita)
  - Controlador (processador)
  - Cabeçote de leitura e escrita (pode ir para esquerda ou direita)

## Complexidade de tempo e espaço

Complexidade de tempo: não representa o tempo diretamente, mas o número de vezes que determinada operação considerada relevante é executada

Complexidade de espaço: representa a quantidade de memória (numa unidade qualquer) que é necessária para armazenar as estruturas de dados associadas ao algoritmo

## Complexidade de pior e melhor caso

A busca sequencial possui complexidade de tempo constante (1) no melhor caso, quando o elemento procurado é o primeiro da lista e linear (n) no pior caso, quando o elemento procurado não está contido na lista ou é o último da lista.

Insertion-sort:

- Melhor caso - dados já estão ordenados
- Pior caso - dados estão em ordem inversa

Funções de taxa de crescimento

- Tempo constante: O(1) (raro)
- Tempo sublinear (log(n)): muito rápido (ótimo)
- Tempo linear: (O(n)): muito rápido (ótimo)
- Tempo nlogn: Comum em algoritmos de divisão e conquista.
- Tempo polinomial nk : Freqüentemente de baixa ordem (k ≤ 10), considerado eficiente.
- Tempo exponencial: 2n , n!, nn considerados intratáveis

> Um crescimento quadrático é considerado pior que um crescimento linear.
