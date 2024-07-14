//  Arquivo: Pto.c

#include "Pto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float x;
  float y;
};

Ponto *Ponto_cria(float x, float y) {
  Ponto *p = (Ponto *)malloc(sizeof(Ponto));

  if (p != NULL) {
    p->x = x;
    p->y = y;
  }
  return p;
}

void Ponto_libera(Ponto *p) {
  free(p);
}

float Ponto_distancia(Ponto *p1, Ponto *p2) {
  if (p1 == NULL || p2 == NULL) {
    return -1;
  }
  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;

  return sqrt(dx * dx + dy * dy);
}

void Print_Ponto(Ponto *p) {
  printf("Ponto (x,y): (%.1f,%.1f)\n", p->x, p->y);
}