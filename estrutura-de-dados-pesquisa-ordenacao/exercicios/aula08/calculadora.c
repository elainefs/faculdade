#include <stdio.h>
#include <locale.h>
#define TAM 2

int topo = -1;
int n1, n2;
int stack[TAM];

int isCheia(){
  if(stack == TAM - 1){
    printf("A pilha está cheia");
  }
}

int isVazia(){
  if(topo == -1){
    printf("A pilha está vazia");
  }
}

int empilhar(int value){
  if(topo == TAM - 1){
    printf("\n Pilha cheia \n");
  } else {
    topo ++;
    stack[topo] = value;
  }
}

int desempilhar(){
  if(topo == -1){
    printf("\n Pilha vazia \n");
    return -1;
  }
  return stack[topo--];
}

int main(){
  int opcao, value;
  setlocale(LC_ALL, "Portuguese");

  printf("Digite o primeiro valor: ");
  scanf("%d", &n1);

  printf("Digite o segundo valor: ");
  scanf("%d", &n2);
  printf("\n Escolha uma operação \n");
  printf("1. Soma \n");
  printf("2. Subtração \n");
  printf("3. Multiplicação \n");
  printf("4. Divisão \n");
  printf("0. Sair \n");
  printf("Opção: ");
  scanf("%d", &opcao);

    switch (opcao){
      case 1:
        int soma = n1 + n2;
        printf("A soma é: %d\n", soma);
        break;
      case 2: 
        int subtracao = n1 - n2;
        printf("A subtração é: %d\n", subtracao);
        break;
      case 3:
        int multiplicacao = n1 * n2;
        printf("A multiplicação é: %d\n", multiplicacao);
        break;
      case 4:
        int divisao = n1 / n2;
        printf("A divisão é: %d\n", divisao);
        break;
      case 0:
        printf("Saindo do programa\n");
      default:
        printf("Valor invalido\n");
        break;
    }
}