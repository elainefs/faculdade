#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  int *ptr = NULL;

  //atribui o endereço de num ao ptr
  ptr = &num;

  printf("Digite um numero inteiro: ");
  scanf("%d", ptr); //guarda no ptr
  //prt armazena o endereco de num
  //logo o valor é guardado em num

  //como ptr referencia o endereço de num 
  //num guarda o endereço digitado
  printf("O valor de num é: %d\n", num);

  return 0;
}