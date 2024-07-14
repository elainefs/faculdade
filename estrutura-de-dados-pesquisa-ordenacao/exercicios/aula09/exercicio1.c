#include <locale.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int Inscricao;
  char Nome[50];
  int Idade;
  char Categoria[2];
} Competidor;

void ImprimeCompetidor(Competidor C) {
  printf("\n\nInscrição: %i\n Nome: %s\n Idade: %i\n Categoria: %s\n\n",
         C.Inscricao, C.Nome, C.Idade, C.Categoria);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  Competidor Competidor1, Competidor2, Competidor3;

  Competidor1.Inscricao = 1;
  strcpy(Competidor1.Nome, "Maria");
  Competidor1.Idade = 15;
  strcpy(Competidor1.Categoria, "F");

  Competidor2.Inscricao = 2;
  strcpy(Competidor2.Nome, "Joao");
  Competidor2.Idade = 25;
  strcpy(Competidor2.Categoria, "M");

  Competidor3.Inscricao = 3;
  strcpy(Competidor3.Nome, "Jose");
  Competidor3.Idade = 35;
  strcpy(Competidor3.Categoria, "M");

  printf("Competidor 1:");
  ImprimeCompetidor(Competidor1);
  printf("Competidor 2:");
  ImprimeCompetidor(Competidor2);
  printf("Competidor 3:");
  ImprimeCompetidor(Competidor3);

  return 0;
}