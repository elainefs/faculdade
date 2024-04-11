#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  float nota1, nota2, media;
  char trabalho[10];

  printf("Nota 1: ");
  scanf("%f", &nota1);
  printf("Nota 2: ");
  scanf("%f", &nota2);
  printf("Fez trabalho (S/N)? ");
  scanf("%s.\n", &trabalho);

  media = (nota1 + nota2) / 2;

  if((media >= 8) && (strcmp(trabalho, "S") == 0)){
    printf("Aluno aprovado.\n");
  } else {
    printf("Fazer exame final.\n");
  }

  printf("Média do aluno = %.1f\n", media);
}
