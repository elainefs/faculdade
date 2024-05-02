#include <stdio.h>
#include <stdlib.h>

int main(){
  //alocar dinamicamente
  int *v = (int*) malloc(10 * sizeof(int));

  //verificar se a alocação ocorreu
  if(v == NULL){
    printf("Erro ao alocar memória\n");
    return 1;
  }

  //inserir números de 0 a 9 no vetor
  for(int i = 0; i < 10; i++){
    v[i] = i;
  }

  //mostrar números na tela
  printf("Os números inseridos sao:\n");
  for(int i = 0; i < 10; i++){
    printf("v[%d] = %d\t", i, v[i]);
  }

  printf("\n");

  //libera a memória alocada com free
  free(v);
  v = NULL;
  return 0;
}