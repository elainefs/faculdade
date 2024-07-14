// Arquivo main.c

#include "Pto.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  float d;
  Ponto *p, *q;

  p = Ponto_cria(2, 5);
  q = Ponto_cria(7, 9);
  // q->x = 2; // Em nenhum momento opera-se direto com os dados - ERRO
  d = Ponto_distancia(p, q);

  Print_Ponto(p);
  Print_Ponto(q);

  printf("Distancia entre pontos: %f \n", d);
  Ponto_libera(q);
  Ponto_libera(p);
  return (0);
}