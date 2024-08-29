# Análise e Projeto de Algoritmos

Algoritmos são o cerne da computação. Eles são uma sequência de passos bem definidos, não ambíguos e finitos que quando executados realizam uma tarefa específica. Eles devem iniciar, processar por um determinado tempo e finalizar.

O **tamanho da entrada** depende do estudo que está sendo realizado.

O **tempo de execução** de um algoritmo é a soma do tempo de execução de cada instrução. É o tempo necessário para executar as instruções (passos) para uma determinada entrada.

## Complexidade de Algoritmos

A complexidade de um algoritmo estuda e define quanto eficiente é um algoritmo em relação ao número de operações necessários para finalizar a tarefa.

Computadores diferentes, mesmo que tenham hardwares idênticos, podem levar tempos diferentes para realizar uma mesma tarefa. Portanto, avaliar o desempenho de um algoritmo apenas com base no tempo de execução é ineficiente.

O cenário utilizado para representar um algoritmo é o de pior caso. Mas o mais comum é arredondar para uma complexidade mais comum, devido a análise assintótica[^1].

[^1]: Forma de julgar quão eficiente é um algoritmo, independente dos recursos utilizados. É uma avaliação de tempo de execução de um algoritmo com um número grande de elementos e entrada.

## Complexidade de pior e melhor caso

A busca sequencial possui complexidade de tempo constante (1) no melhor caso quando o elemento procurado é o primeiro da lista e linear (n) no pior caso quando o elemento procurado não está contido na lista ou é o último da lista.

- Melhor caso: o elemento procurado é o primeiro da lista = 1
- Caso médio: o elemento procurado está no centro = n/2
- Pior caso: o elemento é o último na lista = n

Insertion sort:

- Melhor caso - dados já estão ordenados
- Pior caso - dados estão em ordem inversa

## Custo Computacional

O custo computacional se refere à quantidade de recursos (tempo, memória) necessários para executar um determinado algoritmo.

A função de complexidade de cada algoritmo é definida pelo custo computacional e para isso deve-se considerar o modelo de máquina.

## Modelos de Máquinas

### Máquina de Turing

- Alan Turing, 1936
- Possui 3 componentes:
  - Fita infinita (memória infinita e irrestrita)
  - Controlador (processador)
  - Cabeçote de leitura e escrita (pode ir para esquerda ou direita)
- Variações
  - Máquina de Turing Determinística
  - Máquina de Turing com Múltiplas Fitas
  - Máquina de Turing Não-Determinística

Um sistema de regras de manipulação de dados é dito Turing-Completo, ou computacionalmente universal, se pode ser usado para simular qualquer Máquina de Turing.

**Equivalência de Turing:** dois computadores, P e Q, são chamados equivalentes se P pode simular Q e Q pode simular P.

**Tese de Church-Turing:**

- Qualquer função cujos valores podem ser calculados por um algoritmo pode ser calculado por uma máquina de Turing.
- Se qualquer computador do mundo real pode simular uma máquina de Turing, é Turing equivalente a uma máquina de Turing.
- Qualquer linguagem de programação de propósito geral é suficiente para expressar qualquer algoritmo.

### RAM: Máquina de Acesso Aleatório

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

É possível ignorar os dispositivos de entrada e saída (teclado, monitor, etc) e assume-se que a codificação do algoritmo e os dados já estão armazenados na memória.

## Complexidade de tempo e espaço

Complexidade de tempo: não representa o tempo diretamente, mas o número de vezes que determinada operação considerada relevante é executada em função do tamanho da entrada (eficiência)

Complexidade de espaço: representa a quantidade de memória (numa unidade qualquer) que é necessária para armazenar as estruturas de dados associadas ao algoritmo

## Notação Assintótica

Usada para representar a complexidade de tempo e espaço.

- O (Ómicron grande);
- Θ (Teta);
- Ω (Ômega grande);
- o (Ómicron pequeno);
- ω (ômega pequeno)

## Funções de taxa de crescimento

- Tempo constante: O(1) (raro)
- Tempo sublinear (logarítmica) (log(n)): muito rápido (ótimo)
  - Funções logarítmicas: Algoritmos com essa complexidade são muito eficientes, mesmo para grandes valores de n.
- Tempo linear: (O(n)): muito rápido (ótimo)
- Tempo nlogn (logarítmica linear): Comum em algoritmos de divisão e conquista.
  - Funções lineares e quase lineares: Algoritmos com essa complexidade são considerados eficientes para a maioria das aplicações.
- Tempo polinomial (quadrática e cúbica) n^k : Frequentemente de baixa ordem (k ≤ 10), considerado eficiente.
  - Funções polinomiais (quadrática, cúbica): Algoritmos com essa complexidade podem ser eficientes para valores moderados de n, mas podem se tornar lentos para valores muito grandes.
- Tempo exponencial: 2^n , n!, nn considerados intratáveis
  - Funções exponenciais: Algoritmos com essa complexidade são geralmente inviáveis para problemas de grande escala, pois o tempo de execução cresce explosivamente com o aumento de n.

Ao medir o número de instruções necessárias para cada algoritmo, devem ser consideradas estruturas de decisão e de repetição. As estruturas de repetição aninhadas são as maiores responsáveis pelo aumento de instruções.

- laços representam linear
- constantes não possuem laços
- laços encadeados representam log

## Polinômios

Polinômios são expressões algébricas formadas pela soma de monômios. Um monômio, por sua vez, é uma expressão algébrica composta por um número (coeficiente) e uma ou mais variáveis elevadas a potências inteiras não negativas.

Exemplo:

Monômios: 3x², -2y, 5

Polinômio: 3x² - 2y + 5

Algoritmos polinomiais são considerados "mais eficientes".

> NP-completo: não existem algoritmos polinomiais

> 1GHz = 10⁹Hz
>
> 10⁹ = 1s