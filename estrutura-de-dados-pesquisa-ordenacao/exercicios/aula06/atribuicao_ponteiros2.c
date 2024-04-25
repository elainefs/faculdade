#include <stdio.h>

void funcao(int *px, int *py) {
  px = py; 					
	py = (*py)*(*px);			
	*px = *px+4;				
}

int main() {

  int x=2, y=3;
   
  funcao(&x,&y);

	printf("x = %d\n",x);
	printf("y = %d\n",y);
 
  return 0;
}