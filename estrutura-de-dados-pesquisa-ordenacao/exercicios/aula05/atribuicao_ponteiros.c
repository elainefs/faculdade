#include <stdio.h>

int main() {
    int i = 2, j; 			
    int *p;

    p = &i;
	*p++;
	j = *p + 5;
	    
    printf("\ni = %d\n", i);
    printf("\nj = %d\n", j);
    printf("\np = %d\n", p);
    printf("\n*p = %d\n", *p);

    return 0;
}