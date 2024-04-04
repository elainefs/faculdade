#include <stdio.h>

int main(void) {
  float salario;
  float imposto;
  float parcela;
  printf("Digite o salario: ");
  scanf("%f", &salario);

  if (salario <= 2259.20) {
    imposto = 0;
  } else {
    if (salario <= 2826.65) {
      parcela = 169.44;
      imposto = (salario * 0.075) - parcela;
    } else if (salario <= 3751.05) {
      parcela = 381.44;
      imposto = (salario * 0.15) - parcela;
    } else if (salario <= 4664.68) {
      parcela = 662.77;
      imposto = (salario * 0.225) - parcela;
    } else {
      parcela = 896.00;
      imposto = (salario * 0.275) - parcela;
    }
  }

  printf("Imposto devido: %.2f\n", imposto);
}