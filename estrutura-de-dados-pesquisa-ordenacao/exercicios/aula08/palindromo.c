#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo de dado para a pilha (caracteres)
char pilha[100];

int verificaPalindromo(char sequencia[]) {
    // Inicializa o índice do topo da pilha
    int topoPilha = -1;

    // Empilha cada caractere da sequência
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (sequencia[i] != ' ' && sequencia[i] != '.') {
            pilha[++topoPilha] = sequencia[i];
        }
    }

    // Verifica se a sequência é um palíndromo
    for (int i = 0; i <= topoPilha / 2; i++) {
        if (pilha[i] != pilha[topoPilha - i]) {
            return 0; // Não é palíndromo
        }
    }

    return 1; // É um palíndromo
}

int main() {
    char sequencia[100];

    printf("Digite a sequência de caracteres: ");
    gets(sequencia); // Lê a sequência completa com espaços

    int resultado = verificaPalindromo(sequencia);

    if (resultado) {
        printf("\"%s\" é um palíndromo!\n", sequencia);
    } else {
        printf("\"%s\" não é um palíndromo.\n", sequencia);
    }

    return 0;
}
