#include <stdio.h>

int main(){
  char vet1[20], vet2[20];
  int i = 0;

  fgets(vet1, 20, stdin);

  for(i = 0; i < 20; i++){
    vet2[i] = vet1[i];
  }

  printf("Vetor 1: %s\n", vet1);
  printf("Vetor 2: %s\n", vet2);
}