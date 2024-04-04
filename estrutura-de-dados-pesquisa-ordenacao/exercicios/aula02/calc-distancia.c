#include <stdio.h>
#include <math.h>

int distancia(int x1, int x2, int y1, int y2){
  int D = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
  return D;
}

int main(void){
  int x1, x2, y1, y2;

  int distanciaValue;

  printf("Digite os pontos (x1, x2, y1, y2): ");
  scanf("%i %i %i %i", &x1, &x2, &y1, &y2);

  distanciaValue = distancia(x1, x2, y1, y2);
  printf("A distancia entre os pontos é: %i\n", distanciaValue);
}