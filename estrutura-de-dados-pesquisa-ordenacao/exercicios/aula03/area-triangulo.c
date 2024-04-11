#include <stdio.h>

int main() {
  float base, altura, area;
  char continuar;

  do {
    do {
      printf("Digite a base do triângulo (valor positivo maior que zero): ");
      scanf("%f", &base);
    } while (base <= 0); // Verifica se a base é maior que zero

    do {
      printf("Digite a altura do triângulo (valor positivo maior que zero): ");
      scanf("%f", &altura);
    } while (altura <= 0); // Verifica se a altura é maior que zero

    area = (base * altura) / 2;

    printf("A área do triângulo é: %.2f\n", area);

    printf("Deseja calcular a área de outro triângulo? (S/N): ");
    scanf(" %c", &continuar); // Adiciona espaço antes de %c
  } while (continuar == 'S' || continuar == 's');

  printf("\nPrograma finalizado.\n");

  return 0;
}
