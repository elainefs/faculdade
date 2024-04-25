#include <stdio.h>

int main(){
  char frase[20];
  int i, cont=0;

  printf("Digite uma frase: ");
  fgets(frase,20,stdin);

  for(i=0; i<20; i++){
    if(frase[i]=='c'){
      cont++;
    }
  }

  printf("Quantidade de letras C na frase: %d\n", cont);
}