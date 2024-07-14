// Arquivo: Pto.h

typedef struct ponto Ponto;

Ponto *Ponto_cria(float x, float y);

void Ponto_libera(Ponto *p);

float Ponto_distancia(Ponto *p1, Ponto *p2);

void Print_Ponto(Ponto *p);