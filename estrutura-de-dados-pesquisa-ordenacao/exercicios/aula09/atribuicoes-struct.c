// SLIDE 19 STRUCT

#include <stdio.h>
#include <string.h>

// Cria uma STRUCT para armazenar os dados de uma pessoa
// typedef struct
typedef struct {
  float Peso;   // define o campo Peso
  int Idade;    // define o campo Idade
  float Altura; // define o campo Altura
} Pessoa;       // define o nome do novo tipo criado

void ImprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
  printf("Idade: %d  Peso: %.1f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}

int main() {
  Pessoa Joao, P2;
  Pessoa Cadastro[10];

  Joao.Idade = 15;
  Joao.Peso = 60.5;
  Joao.Altura = 1.75;

  Cadastro[4].Idade = 23;
  Cadastro[4].Peso = 75.3;
  Cadastro[4].Altura = 1.89;

  P2 = Cadastro[4];
  P2.Idade++;

  // chama a função que recebe a struct como parâmetro
  printf("Joao....: ");
  ImprimePessoa(Joao);
  printf("Cadastro: ");
  ImprimePessoa(Cadastro[4]);
  printf("P2......: ");
  ImprimePessoa(P2);
  return 0;
}