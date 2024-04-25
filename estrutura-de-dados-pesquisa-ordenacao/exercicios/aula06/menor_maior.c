#include <stdio.h>

void encontrarMinMax(int *vetor, int tamanho, int *min, int *max) {
  // Inicializar min e max com o primeiro elemento do vetor
  *min = *vetor;
  *max = *vetor;

  // Percorrer o vetor para encontrar o menor e o maior valor
  for (int i = 1; i < tamanho; i++) {
    if (*(vetor + i) < *min) {
        *min = *(vetor + i);
    }
    if (*(vetor + i) > *max) {
        *max = *(vetor + i);
    }
  }
}

int main() {
  int vetor[100]; // Tamanho máximo do vetor
  int tamanho, min, max;

  // Pedir ao usuário para inserir o tamanho do vetor
  printf("Digite o tamanho do vetor (max. 100): ");
  scanf("%d", &tamanho);

  // Pedir ao usuário para inserir os elementos do vetor
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < tamanho; i++) {
      printf("Elemento %d: ", i + 1);
      scanf("%d", &vetor[i]);
  }

  // Encontrar o menor e o maior valor do vetor
  encontrarMinMax(vetor, tamanho, &min, &max);

  // Imprimir o menor e o maior valor do vetor
  printf("Menor valor do vetor: %d\n", min);
  printf("Maior valor do vetor: %d\n", max);

  return 0;
}