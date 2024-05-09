#include <stdio.h>

#define MAX_SIZE 100

char data[MAX_SIZE];
int top = -1;

void initializeStack() {
    top = -1;
}

int isStackEmpty() {
    return top == -1;
}

void push(char character) {
    if (top == MAX_SIZE - 1) {
        printf("Pilha cheia!\n");
        return;
    }

    top++;
    data[top] = character;
}

char pop() {
    if (isStackEmpty()) {
        printf("Pilha vazia!\n");
        return '\0';
    }

    top--;
    return data[top];
}

int isBalancedParentheses(char *expression) {
    initializeStack();

    char stack[MAX_SIZE]; // Pilha auxiliar para tipos de parênteses
    int topStack = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentCharacter = expression[i];

        if (currentCharacter == '(') {
            push(currentCharacter);
            stack[++topStack] = '(';
        } else if (currentCharacter == ')') {
            if (isStackEmpty() || stack[topStack] != '(') {
                return 0; // Parêntese de fechamento sem abertura ou tipo inconsistente
            }

            pop();
            topStack--;
        }
    }

    return isStackEmpty() && topStack == -1; // Verifica se ambas as pilhas estão vazias
}

int main() {
    char expression[MAX_SIZE];
    printf("Digite a expressão com parênteses: ");
    scanf("%s", expression);

    int isBalanced = isBalancedParentheses(expression);

    if (isBalanced) {
        printf("Expressão balanceada.\n");
    } else {
        printf("Expressão não balanceada.\n");
    }

    return 0;
}
