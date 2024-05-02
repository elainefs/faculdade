#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declaração de variáveis
  int tamanhoVetor, *vetor1, *vetor2, *vetorSoma;
  int i;

  // Solicita e valida o tamanho dos vetores
  printf("Digite o tamanho dos vetores: ");
  scanf("%d", &tamanhoVetor);

  if (tamanhoVetor <= 0) {
    printf("Erro: Tamanho inválido!\n");
    return 1;
  }

  // Alocação dinâmica dos vetores
  vetor1 = (int *)malloc(tamanhoVetor * sizeof(int));
  vetor2 = (int *)malloc(tamanhoVetor * sizeof(int));
  vetorSoma = (int *)malloc(tamanhoVetor * sizeof(int));

  if (vetor1 == NULL || vetor2 == NULL || vetorSoma == NULL) {
    printf("Erro: Falha na alocação de memória!\n");
    return 1;
  }

  // Leitura dos valores dos vetores 1 e 2
  printf("\nDigite os valores do vetor 1:\n");
  for (i = 0; i < tamanhoVetor; i++) {
    scanf("%d", &vetor1[i]);
  }

  printf("\nDigite os valores do vetor 2:\n");
  for (i = 0; i < tamanhoVetor; i++) {
    scanf("%d", &vetor2[i]);
  }

  // Cálculo da soma dos vetores
  for (i = 0; i < tamanhoVetor; i++) {
    vetorSoma[i] = vetor1[i] + vetor2[i];
  }

  // Impressão dos vetores
  printf("\n\nVetor 1:");
  for (i = 0; i < tamanhoVetor; i++) {
    printf(" %d", vetor1[i]);
  }

  printf("\nVetor 2:");
  for (i = 0; i < tamanhoVetor; i++) {
    printf(" %d", vetor2[i]);
  }

  printf("\nVetor Soma:");
  for (i = 0; i < tamanhoVetor; i++) {
    printf(" %d\n", vetorSoma[i]);
  }

  // Liberação da memória alocada
  free(vetor1);
  free(vetor2);
  free(vetorSoma);

  return 0;
}
