#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int inicio = -1;
int fim = -1;

// Função para verificar se a fila está vazia
int isEmpty() {
    return inicio == -1 && fim == -1;
}

// Função para verificar se a fila está cheia
int isFull() {
    return fim == SIZE - 1;
}

// Função para inserir um elemento na fila
void enqueue(int value) {
    if (isFull()) {
        printf("Erro: a fila está cheia.\n");
        return;
    } else if (isEmpty()) {
        inicio = fim = 0;
    } else {
        fim++;
    }
    queue[fim] = value;
}

// Função para remover e retornar um elemento da fila
int dequeue() {
    if (isEmpty()) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    } else if (inicio == fim) {
        int value = queue[inicio];
        inicio = fim = -1;
        return value;
    } else {
        return queue[inicio++];
    }
}

int main() {
    // Inserindo elementos na fila
    printf("Enfileirar Elemento 10: \n");
    	enqueue(10);
	printf("Enfileirar Elemento 20: \n");
		enqueue(20);
    printf("Enfileirar Elemento 30: \n");
    	enqueue(30);
    
    
	printf("\n=======================\n\n");
    
	// Removendo e exibindo elementos da fila
    printf("Desenvileirar Elemento: %d\n", dequeue());
    printf("Desenvileirar Elemento: %d\n", dequeue());
    printf("Desenvileirar Elemento: %d\n", dequeue());
        
    return 0;
}