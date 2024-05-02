#include <stdio.h>
#include <stdlib.h>

int main(){
  char vs[5] = {0,10,20,30,40};
  
  printf("Endereco %p\n", &vs);
  printf("Endereco %p\n", vs);

  for (int i = 0; i < 5; i++) {
    printf("Endereço do elemento vs[%d]: %p - Valor: %d\n", i, &vs[i], vs[i]);
  }

  int *vh_mal = malloc(5 * sizeof(int));

  printf("Endereço do vetor vh_mal: %p\n", vh_mal);
  printf("Endereço do primeiro elemento (vh_mal[0]): %p\n", vh_mal[0]);

  for (int i = 0; i < 5; i++) {
    printf("Endereço do elemento vh_mal[%d]: %p - Valor: %d\n", i, &vh_mal[i], vh_mal[i]);
  }

  int *vh_cal = calloc(5, sizeof(int));

  printf("Endereço do vetor vh_cal: %p\n", vh_cal);
  printf("Endereço do primeiro elemento (vh_0]): %p\n", vh_cal[0]);

  for (int i = 0; i < 5; i++) {
    printf("Endereço do elemento vh_cal[%d]: %p - Valor: %d\n", i, &vh_cal[i], vh_cal[i]);
  }


}