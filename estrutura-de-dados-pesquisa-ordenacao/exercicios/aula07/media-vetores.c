#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declaração de variáveis
  int n, *numeros, i;
  float media;

  // Solicita e valida a quantidade de números
  printf("Digite a quantidade de números: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Erro: Quantidade inválida!\n");
    return 1;
  }

  // Alocação dinâmica do vetor
  numeros = (int *)malloc(n * sizeof(int));

  if (numeros == NULL) {
    printf("Erro: Falha na alocação de memória!\n");
    return 1;
  }

  // Leitura dos números
  printf("\nDigite os números:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &numeros[i]);
  }

  // Cálculo da média
  media = 0;
  for (i = 0; i < n; i++) {
    media += numeros[i];
  }
  media /= n;

  // Impressão do vetor e da média
  printf("\nVetor lido:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", numeros[i]);
  }

  printf("\nMédia: %.2f\n", media);

  // Liberação da memória alocada
  free(numeros);

  return 0;
}
