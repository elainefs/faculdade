#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 10;
	int *p1 = NULL;
	int *p2;
	printf(">>> APOS DECLARACAO DAS VARIAVEIS <<<\n");
	printf("=====================================\n");
	printf("Endereco	n : %p\n",&n);
	printf("Endereco 	p1: %p\n",&p1);
	printf("Endereco 	p2: %p\n\n",&p2);
		
	printf("Conteudo	n : %d\n",n);
	printf("Conteudo 	p1: %d\n",p1);
	printf("Conteudo 	p2: %d\n",p2);	
	
	p1 = &n;
	p2 = p1;
	*p2 = 5;
	
	printf("\n\n>>> APOS ATRIBUICOES NAS VARIAVEIS <<<\n");
	printf("=====================================\n");
	printf("Endereco	n : %p\n",&n);
	printf("Endereco 	p1: %p\n",&p1);
	printf("Endereco 	p2: %p\n\n",&p2);
		
	printf("Conteudo	n : %d\n",n);
	printf("Conteudo 	p1: %d\n",p1);
	printf("Conteudo 	p2: %d\n",p2);
}