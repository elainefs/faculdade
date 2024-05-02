#include <stdio.h>
#include <stdlib.h>
#define TAM 15

int main(){
  //alocação dinâmica de números inteiros quantidade definida pela constante TAM
  int *v = (int*) malloc(TAM * sizeof(int));

  //verificar se a alocação foi feita
  if(v == NULL){
    printf("Erro ao alocar memoria\n");
    return 1;
  }

  //inserir números no vetor
  for(int i = 0; i < TAM; i++){
    v[i] = i;
  }

  //apresentar números na tela
  printf("Os numeros inseridos sao:\n");
  for(int i = 0; i < TAM; i++){
    printf("v[%d]=%d\t", i, v[i]);
  }
  printf("\n");

  //liberar memória
  free(v);
  v = NULL;
  return 0;
}