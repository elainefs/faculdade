#include <stdio.h>
#include <locale.h>
#define TAM 10 //tamanho máximo da pilha

int stack[TAM]; // declaração da pilha
int topo = -1; // inicialização do topo da pilha

int isVazia(){
  return topo == -1;
}

int isCheia(){
  return topo == TAM - 1;
}

// função para empilhar um elemento
int empilhar(int value){
  if(topo == TAM - 1){
    printf("\n** Pilha cheia **\n");
    return;
  } else {
    topo++;
    stack[topo] = value;
  }
}

// função para desempilhar um elemento
int desempilhar(){
  if(topo == -1){
    printf("\n** Pilha vazia ** \n");
    return -1;
  } 
  return stack[topo--];    
}

// função para exibir elemento no topo da pilha
int Topo(){
  if(topo == -1){
    printf("A pilha está vazia\n");
    return;
  } else {
    printf("Elemento no topo: %d\n", stack[topo]);
  }
}

int main(){
  int opcao, value;
  setlocale(LC_ALL, "Portuguese");

  do {
    printf("\n Escolha uma operação: \n");
    printf("1. Empilhar \n");
    printf("2. Desempilhar \n");
    printf("3. Verificar se a pilha está vazia \n");
    printf("4. Verificar se a pilha está cheia \n");
    printf("5. Mostrar o elemento no topo da pilha \n");
    printf("0. Sair \n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Digite o valor a ser empilhado: ");
        scanf("%d", &value);
        empilhar(value);
        break;
      case 2:
        value = desempilhar();
        if(value != -1){
          printf("Elemento desempilhado: %d\n", value);      
        }
        break;
      case 3:
        if(isVazia()){
          printf("A pilha esta vazia\n");
        } else {
          printf("A pilha não está vazia\n");
        }
        break;
      case 4:
        if(isCheia()){
          printf("A pilha está cheia\n");
        } else {
          printf("A pilha não está cheia\n");
        }      
        break;
      case 5:
        Topo();
        break;
      case 0:
        printf("Saindo do programa\n");
        break;
      default:
        printf("Opção invalida\n");
        break;
    }
  } while(opcao != 0);

  return 0;
}