#include <stdio.h>

int main(void){
  float nota1, nota2, media;

  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);
  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  media = (nota1 + nota2) / 2;

  if(media >= 8) {
    printf("Aluno aprovado.\n");
  } else {
    printf("Fazer exame final.\n");
  }

  printf("Média do aluno = %.1f\n", media);
}