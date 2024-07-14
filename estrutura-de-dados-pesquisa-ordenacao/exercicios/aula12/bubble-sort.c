////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Ordenação-Pesquisa Memória - Slide 8 - BubbleSort
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// // Função para ordenar vetor usando Bubble Sort
// void bubbleSort(int vetor[], int tamanho) {
//   int i, j, temp;
//   for (i = 0; i < tamanho - 1; i++) {
//     for (j = 0; j < tamanho - i - 1; j++) {
//       if (vetor[j] > vetor[j + 1]) {
//         // Troca os elementos fora de ordem
//         temp = vetor[j];
//         vetor[j] = vetor[j + 1];
//         vetor[j + 1] = temp;
//       }
//     }
//   }
// }

// int main() {
//   int vetor[5];
//   int i;

//   // Solicita ao usuário que insira os números
//   printf("Insira 5 números inteiros:\n");

//   // Lê os números e armazena no vetor
//   for (i = 0; i < 5; i++) {
//     scanf("%d", &vetor[i]);
//   }

//   // Chama a função bubbleSort para ordenar o vetor
//   bubbleSort(vetor, 5);

//   // Mostra o vetor ordenado
//   printf("\nVetor ordenado:\n");
//   for (i = 0; i < 5; i++) {
//     printf("%d ", vetor[i]);
//   }
//   printf("\n");

//   return 0;
// }


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Ordenação-Pesquisa Memória - Slide 15 - QuickSort
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// // Função para trocar dois elementos de posição no array
// void trocar(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Função para particionar o array e retornar o índice do pivô
// int particionar(int array[], int inicio, int fim) {
//     int pivo = array[fim]; // Escolhendo o último elemento como pivô
//     int i = (inicio - 1); // Índice do menor elemento

//     for (int j = inicio; j <= fim - 1; j++) {
//         // Se o elemento atual for menor ou igual ao pivô
//         if (array[j] <= pivo) {
//             i++; // Incrementa o índice do menor elemento
//             trocar(&array[i], &array[j]);
//         }
//     }
//     trocar(&array[i + 1], &array[fim]);
//     return (i + 1);
// }

// // Função principal do Quicksort
// void quicksort(int array[], int inicio, int fim) {
//     if (inicio < fim) {
//         // Obtém o índice do pivô
//         int indice_pivo = particionar(array, inicio, fim);

//         // Ordena os elementos antes e depois do pivô recursivamente
//         quicksort(array, inicio, indice_pivo - 1);
//         quicksort(array, indice_pivo + 1, fim);
//     }
// }

// int main() {
//     int array[] = {10, 7, 8, 9, 1, 5};
//     int tamanho = sizeof(array) / sizeof(array[0]);

//     printf("Array original:\n");
//     for (int i = 0; i < tamanho; i++) {
//         printf("%d ", array[i]);
//     }

//     quicksort(array, 0, tamanho - 1);

//     printf("\n\nArray ordenado:\n");
//     for (int i = 0; i < tamanho; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Ordenação-Pesquisa Memória - Slide 27 - Pesquisa Binária
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// // Função para realizar a pesquisa binária
// int pesquisaBinaria(int vetor[], int tamanho, int elemento) {
//     int inicio = 0;
//     int fim = tamanho - 1;
//     int meio;

//     while (inicio <= fim) {
//         meio = (inicio + fim) / 2;

//         // Se o elemento for encontrado no meio do vetor
//         if (vetor[meio] == elemento)
//             return meio;

//         // Se o elemento estiver na metade esquerda do vetor
//         else if (vetor[meio] > elemento)
//             fim = meio - 1;

//         // Se o elemento estiver na metade direita do vetor
//         else
//             inicio = meio + 1;
//     }

//     // Se o elemento não estiver presente no vetor
//     return -1;
// }

// int main() {
//     int vetor[100];
//     int elemento, posicao;

//     // Preenchendo o vetor com números inteiros de 1 a 100
//     for (int i = 0; i < 100; i++) {
//         vetor[i] = i + 1;
//     }

//     // Solicitando ao usuário o elemento a ser pesquisado
//     printf("Digite o elemento que deseja encontrar: ");
//     scanf("%d", &elemento);

//     // Realizando a pesquisa binária
//     posicao = pesquisaBinaria(vetor, 100, elemento);

//     // Verificando se o elemento foi encontrado
//     if (posicao != -1)
//         printf("O elemento %d foi encontrado na posição %d.\n", elemento, posicao);
//     else
//         printf("O elemento %d nao foi encontrado no vetor.\n", elemento);

//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Recursividade - Slide 6 - Fatorial - Solução iterativa
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// int fatorial(int num){
//     int i, resultado = 1;
//     for(i = 1; i <= num; i++){
// 	resultado = resultado * i;
//     }
//     return resultado;
// }
// int main(){
//     int num, resultado;
//     printf("Digite o numero que deseja calcular o fatorial: ");
//     scanf("%d", &num);
//     if(num < 0){
//         printf("\nErro: Numero negativo!");
//     }else{
//         resultado = fatorial(num);
//         printf("Resultado: %d\n", resultado);
//     }
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Recursividade - Slide 6 - Fatorial - Cálculo de fatorial com função recursiva
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// //Função recursiva que calcula o fatorial de um numero inteiro n
// int fatorial(int n){
//     int vfat;
//     //Caso base: fatorial de n == 0 retorna 1
//     if(n == 0){
//         return 1;
//     }else{
//         //Chamada recursiva
//         vfat = n * fatorial(n - 1);
//         return vfat;
//     }
// }
// int main(){
//     int numero, fat;
//     printf("Digite o numero que deseja calcular o fatorial recursivamente: ");
//     scanf("%d",&numero);
//     //chamada da função fatorial
//     if(numero < 0){
//         printf("Erro: Numero negativo!");
//     }else{
//         fat = fatorial(numero);
//         printf("Fatorial de %d = %d\n",numero,fat);
//     }
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Recursividade - Slide 8 - Fibonacci - não recursivo
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// int fibonacci(int n) {
//     if (n <= 1)
//         return n;

//     int a = 0, b = 1, result;
//     for (int i = 2; i <= n; i++) {
//         result = a + b;
//         a = b;
//         b = result;
//     }
//     return result;
// }

// int main() {
//     int n;

//     printf("Digite o valor de n para calcular o termo n da sequência Fibonacci: ");
//     scanf("%d", &n);

//     printf("O termo %d da sequência Fibonacci é: %d\n", n, fibonacci(n));

//     return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aula Recursividade - Slide 10 - Fibonacci recursivo
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Digite o valor de n para calcular o termo n da sequência Fibonacci: ");
    scanf("%d", &n);

    printf("O termo %d da sequência Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}


