// SLIDE 16 STRUCT

#include <stdio.h>
#include <string.h>

// Definição da struct Aluno
struct Aluno {
  int matricula;
  char nome[50];
  int idade;
};

int main() {
  // Declaração de uma variável do tipo Aluno
  struct Aluno aluno1;

  // Atribuição de valores aos campos da struct
  aluno1.matricula = 12345;
  strcpy(aluno1.nome, "Carlos Gutierrez");
  aluno1.idade = 18;

  // struct Aluno aluno2;
  // aluno2 = aluno1;
  // printf("Aluno 2: %d\n", aluno2.matricula);

  // Exibindo os dados do aluno
  printf("Matricula: %d\n", aluno1.matricula);
  printf("Nome.....: %s\n", aluno1.nome);
  printf("Idade....: %d\n", aluno1.idade);

  return 0;
}

// OBS: para declarar aluno 1, precisa da palavra STRUCT