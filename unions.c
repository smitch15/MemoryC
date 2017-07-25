#include <stdio.h>
#include <stdlib.h>

int main(){
	// print sizes of different data types
	printf("size of float: %lu\n", sizeof(float));
	printf("size of double: %lu\n", sizeof(double));
	printf("size of int: %lu\n", sizeof(int));
	printf("size of 1.0: %lu\n", sizeof(1.0));
	// declare byte union to store values in bytes for float val
	union floatByteType {
		char byteArr[4];
		float floatVal;
	};
	typedef union floatByteType fbType;
	fbType fb;
	// fb and float/byte[4] sizes the same
	printf("size of float/byte union type: %lu\n", sizeof(fb));
	
	// populate float union val
	fb.floatVal = 4.19;

	// populate byte part of union
	/*
	char c = 'a';
	for (int i = 0; i < sizeof(fb.byteArr); i++){
		fb.byteArr[i] = c + i;
	}
	*/

	// printf %s gives seg fault, but printf %c gives correct char
	for (int i = 0; i < sizeof(fb); i++){
		printf("fb byte %d: %c\n", i, fb.byteArr[i]);
	}
	printf("byteArr float (float): %f\n", fb.floatVal);
	printf("byteArr float (unsigned int): %x\n", (unsigned int) fb.floatVal);
	return 0;
}
