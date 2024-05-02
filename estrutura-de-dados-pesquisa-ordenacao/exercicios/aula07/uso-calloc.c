#include <stdio.h>
#include <stdlib.h>

int main(){
  int *v, i;
  // aloca memória
  v = (int*) calloc(10, sizeof(int));

  // verifica se alocou corretamente
  if(v == NULL){
    printf("Memoria insuficiente\n");
  } else {
    // utiliza a memória alocada
    for (i = 0; i < 10; i++){
      v[i] = i;
    }

    printf("%d\n", v[0]);
    printf("%d\n", v[9]);
  }

  return 0;
}