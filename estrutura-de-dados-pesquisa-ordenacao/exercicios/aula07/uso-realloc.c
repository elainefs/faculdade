#include <stdio.h>
#include <stdlib.h>

int main(){
  int *array;
  int tamanho_inicial, novo_tamanho;

  //solicita o tamanho inicial
  printf("Digite o tamanho inicial do array: ");
  scanf("%d", &tamanho_inicial);

  //alocação da memória para o tamanho inicial
  array = (int*) malloc(tamanho_inicial * sizeof(int));

  if(array == NULL){
    printf("Erro ao alocar a memória\n");
    return 1;
  }

  //preencher o vetor com os valores iniciais
  printf("Digite %d numeros inteiros:\n", tamanho_inicial);
  for(int i = 0; i < tamanho_inicial; i++){
    scanf("%d", &array[i]);
  }

  //exibir os valores inicias
  printf("Valores inicias:\n");
  for(int i = 0; i < tamanho_inicial; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  //solicitar o novo tamanho (maior que o primeiro)
  printf("Digite o novo tamanho do array: ");
  scanf("%d", &novo_tamanho);

  //realocar memória para novo tamanho
  array = (int*)realloc(array, novo_tamanho * sizeof(int));
  if(array == NULL){
    printf("Erro ao realocar a memoria");
    return 1;
  }

  //preencher o restante do array com novos valores
  printf("Digite mais %d numero inteiros\n", novo_tamanho - tamanho_inicial);
  for(int i = tamanho_inicial; i < novo_tamanho; i++){
    scanf("%d", &array[i]);
  }

  //exibir os valores atualizados
  printf("Valores atualizados:\n");
  for(int i = 0; i < novo_tamanho; i++){
    printf("%d ", array[i]);
  }

  printf("\n");

  //liberar memória
  free(array);
  array = NULL;
  return 0;
}