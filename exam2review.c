#include <stdio.h>
#include <stdlib.h>

#define FOO(t, m)	(unsigned long)(&((t*)0)->m)

int main(){
	// unsigned int i, *p, **q;
	// i = 2;
	// p = &i;
	// q = &(&i) //gives compilation error, cannot take the address of an address
	// printf("%p, %d\n", *p, i);
	// return 0;

	unsigned int h, r;
	printf("%d\n", h);
	h = FOO(h, r);
	printf("%d\n", h);
	return 0;
}
