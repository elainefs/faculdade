#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  int *ptr = NULL;

  ptr = &num;

  printf("Digite um numero inteiro: ");
  scanf("%d", ptr);

  printf("O valor de num é: %d\n", num);

  return 0;
}