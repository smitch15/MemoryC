#include <stdio.h>
#include <stdlib.h>

int main(){
	// still need to malloc rest of array and free the space afterwards
	int *intPtr = (int*)malloc(sizeof(int*));
	int *firstAddr = intPtr;
	for (int i = 0; i < 10; i++){
		*intPtr = i;
		printf("intPtr val is %d, intPtr is, %p\n", *intPtr, intPtr);
		intPtr++;
	}
	intPtr = firstAddr;
	for (int i = 0; i < 10; i++) {
		printf("address of intPtr[i] is %p, value of intPtr[i] is  %d\n", &intPtr[i], intPtr[i]);
	}

	return 0;
}
