#include <stdio.h>
#include <stdlib.h>

// understand struct padding
int main() {
	typedef struct cStructType{
		char z;
		int a;
		char b;
		char d;
		char f;
		int e;
	} cStruct;
	/* char z will be padded with 3 bytes
	 * int will take up 4 bytes
	 * chars b and d will take up 2 bytes but then be padded by 2 bytes
	 * int e will take up 4 bytes
	 */
	cStruct c = {.z = 'z', .a = 4, .b = 'b', .d = 'd', .e = 3};
	printf("&cStruct: %p, ccStruct.z char: %p, Struct.a int: %p, cStruct.b char: %p, cStruct.b char: %p, ", &c, &c.z, &c.a, &c.b, &c.d);
	printf("ccStruct.f int: %p, Struct.e int: %p\n", &c.f, &c.e);
	return 0;
}
