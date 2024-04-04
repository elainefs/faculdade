#include <stdio.h>
#include <math.h>

int main(void){
  int valorLata = 20; // 1 lata custa 20 reais
  int qtdLitrosPorLata = 5; // 1 lata tem 5 litros
  int qtdMetrosPorLitro = 3; // 1 litro pinta 3 metros
  int lateral;

  printf("Tamanho da lateral: ");
  scanf("%i", &lateral);

  float area = 5 * pow(lateral, 2);
  float qtdLitrosNecessario = area / qtdMetrosPorLitro;
  float qtdLatasNecessario = qtdLitrosNecessario / qtdLitrosPorLata;
  float custoTotal = valorLata * qtdLatasNecessario;

  printf("Quantidade de latas: %.2f\n", qtdLatasNecessario);
  printf("Custo Total: %.2f\n", custoTotal);
}
