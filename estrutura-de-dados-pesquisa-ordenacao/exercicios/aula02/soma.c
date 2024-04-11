#include <stdio.h>

int soma(int n1, int n2) {
  int soma = n1 + n2;
  return soma;
}

int main(){
  int resultado = soma(10,20);
  printf("Soma = %d\n", resultado);
  return 0;
}