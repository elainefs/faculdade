#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declaração de variáveis
  int nAlunos, i;
  float *aval1, *aval2, media, maiorNota;

  // Solicita e valida o número de alunos
  printf("Digite o número de alunos: ");
  scanf("%d", &nAlunos);

  if (nAlunos <= 0) {
    printf("Erro: Número de alunos inválido!\n");
    return 1;
  }

  // Alocação dinâmica dos vetores
  aval1 = (float *)malloc(nAlunos * sizeof(float));
  aval2 = (float *)malloc(nAlunos * sizeof(float));

  if (aval1 == NULL || aval2 == NULL) {
    printf("Erro: Falha na alocação de memória!\n");
    return 1;
  }

  // Leitura das notas
  printf("\nDigite as notas:\n");
  for (i = 0; i < nAlunos; i++) {
    printf("Aluno %d - Avaliação 1: ", i + 1);
    scanf("%f", &aval1[i]);

    printf("Aluno %d - Avaliação 2: ", i + 1);
    scanf("%f", &aval2[i]);
  }

  // Cálculo e impressão das médias
  printf("\n\nMédias das notas:\n");
  for (i = 0; i < nAlunos; i++) {
    media = (aval1[i] + aval2[i]) / 2;
    printf("Aluno %d: %.2f\n", i + 1, media);
  }

  // Encontrando a maior nota
  maiorNota = aval1[0];
  for (i = 1; i < nAlunos; i++) {
    if (aval1[i] > maiorNota) {
      maiorNota = aval1[i];
    }

    if (aval2[i] > maiorNota) {
      maiorNota = aval2[i];
    }
  }

  // Impressão da maior nota
  printf("\nMaior nota: %.2f\n", maiorNota);

  // Liberação da memória alocada
  free(aval1);
  free(aval2);

  return 0;
}
