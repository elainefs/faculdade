#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c) {
  float d = pow(b, 2) - 4 * a * c;
  return d;
}

int main(void) {
  float a, b, c;
  float deltaValue;

  printf("Digite os coeficientes: ");
  scanf("%f %f %f", &a, &b, &c);

  deltaValue = delta(a, b, c);
  printf("Delta: %f\n", deltaValue);  
  return 0;
}