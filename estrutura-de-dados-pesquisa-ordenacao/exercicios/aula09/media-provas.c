// SLIDE 4 STRUCT

#include <stdio.h>
int main() {
  // redefinicao do tipo float como nota
  typedef float nota;

  // declarando variaveis com tipo de dados renomeado

  nota prova1 = 0, prova2 = 0, media = 0;
  printf("Digite a nota da primeira prova: ");
  scanf("%f", &prova1);
  printf("Digite nota da segunda prova: ");
  scanf("%f", &prova2);

  media = (prova1 + prova2) / 2;

  printf("Media do aluno = %.1f\n", media);
  return 0;
}