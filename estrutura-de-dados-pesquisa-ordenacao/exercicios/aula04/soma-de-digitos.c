#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
  setlocale(LC_ALL, "Portuguese");
  
  int numero;

  printf("Digite um número entre 1000 e 9999: ");
  scanf("%i", &numero);
  printf("numero digitado: %i\n", numero);

  int digito_milhar = numero / 1000 ;
  int digito_centena = (numero % 1000) / 100;
  int digito_dezena = (numero % 100) / 10;
  int digito_unidade = numero % 10;

  int juntar_2_primeiros = digito_milhar + digito_centena;
  int juntar_2_ultimos = digito_dezena + digito_unidade;

  printf("Soma 2 primeiros: %i\n", juntar_2_primeiros);
  printf("Soma 2 últimos: %i\n", juntar_2_ultimos);  
}