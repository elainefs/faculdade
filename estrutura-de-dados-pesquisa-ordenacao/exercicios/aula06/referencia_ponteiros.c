#include <stdio.h>

int main() {
int var=15;
int *ptr;

ptr = &var;
  printf("Conteudo de 'var'           = %d\n",var);
  printf("Endereco de 'var'           = %p\n",&var);
  printf("Conteudo apontado por 'ptr' = %d\n",*ptr);				
  printf("Endereco apontado por 'ptr' = %p\n",ptr);
  printf("Endereco do 'ptr'           = %p\n",&ptr);
  
*ptr = 20;
  printf("\n\n");
  printf("Conteudo de 'var'           = %d\n",var);
  printf("Endereco de 'var'           = %p\n",&var);
  printf("Conteudo apontado por 'ptr' = %d\n",*ptr);				
  printf("Endereco apontado por 'ptr' = %p\n",ptr);
  printf("Endereco do 'ptr'           = %p\n",&ptr);	
return 0;
}