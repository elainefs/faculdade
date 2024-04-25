#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define N 50

// Converter para minúscula
int strlwr(char *str){
  int i = 0;
  while (str[i] != '\0'){
    str[i] = tolower(str[i]);
    i++;
  }
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  
  char frase[N], frase_invertida[N];
  int tamanho, qtd_vogais = 0;

  printf("Digite uma frase (tam. max=50): ");
  fgets(frase, N, stdin);

  strlwr(frase);
  strlwr(frase_invertida);

  tamanho = strlen(frase);

  // Inverte a frase
  for(int i = 0; i < tamanho; i++){
    frase_invertida[i] = frase[tamanho - i - 1];
  }
  
  // Quantidade de vogais
  for(int j = 0; j < tamanho; j++){
    if(frase[j] == 'a' || frase[j] == 'e' || frase[j] == 'i' || frase[j] == 'o' || frase[j] == 'u'){
      qtd_vogais++;
    }
  }

  printf("Frase normal: %s\n", frase);
  printf("Tamanho da frase: %d\n", tamanho-1); 
  printf("Quantidade de vogais: %i\n", qtd_vogais);
  printf("Frase invertida: %s\n", frase_invertida);
}