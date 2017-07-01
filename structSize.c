#include <stdio.h>
#include <stdlib.h>

int main() {
	typedef struct cStructType{
		char z;
		int a;
		char b;
	} cStruct;
	
	cStruct c = {.z = 'z', .a = 4, .b = 'b'};
	printf("&cStruct: %p, ccStruct.z: %p, Struct.a: %p, cStruct.b: %p\n", &c, &c.z, &c.a, &c.b);
	return 0;
}
