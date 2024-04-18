#include <stdio.h>

void soma(int x, int y, int *z) {
  *z = x + y;
}

int main() {
  int a = 10;
  int b = 20;
  int c;
  soma(a, b, &c);

  printf("Resultado = %d\n", c);
  return 0;
}