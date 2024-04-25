#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 25

int main(){
  setlocale(LC_ALL, "Portuguese");

  char str1[N] = {"Elaine "};
  char str2[N] = {"Ferreira"};
  char str3[N];

  printf("Antes do strcat: \n");
  printf("Str1: %s\n", str1);
  printf("Str2: %s\n", str2);

  strcpy(str3, strcat(str1, str2));

  printf("\n Depois de strcat: \n");
  printf("Str3: %s\n", str3);
}