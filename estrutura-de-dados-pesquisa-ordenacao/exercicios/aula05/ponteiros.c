#include <stdio.h>

int main() {
	char	c = 'G';
	int 	i = 5;
	float	f = 3.14;
	double	d = 2.358;
	
	printf("Endereco CHAR	  c: %p\n",&c);
	printf("Endereco INT	  i: %p\n",&i);
	printf("Endereco FLOAT	  f: %p\n",&f);
	printf("Endereco DOUBLE	  d: %p\n\n",&d);
	
	printf("Conteudo CHAR	  c: %c		Tam.:%d\n",c,sizeof(c));
	printf("Conteudo INT  	  i: %d		Tam.:%d\n",i,sizeof(i));
	printf("Conteudo FLOAT    f: %.2f	Tam.:%d\n",f,sizeof(f));
	printf("Conteudo DOUBLE	  d: %.3lf	Tam.:%d\n\n",d,sizeof(d));
}