#include <stdio.h>
#include <stdlib.h>


void test123(char *arrPtr, int size){
	for (int i = 0; i < size; i++){
		printf("%c\n", arrPtr[i]);
	}
	arrPtr[0] = 'z';
}


int main(){
	// dynamically allocate an array
	printf("How long do you want your array to be?\n");
	int size;
	scanf("%d", &size);
	printf("%d\n", size);
	//char arrPtr[size];
	char *arrPtr = (char *)malloc(size * sizeof(char));
	char charIn;
	char test[5] = {'a','b','c','d','e'};
	//arrPtr[0] = 's';
	char *originalAdd = arrPtr;
	for (int i = 0; i < size; i++){
		//printf("i is %d\n", i);
		//scanf(" %c", &charIn);
		//arrPtr[i] = test[i];
		*arrPtr = test[i];
		//printf("new char is %c\n", *arrPtr);
		arrPtr++;
	}

	arrPtr = originalAdd;
	test123(arrPtr, size);
	arrPtr = originalAdd;
	printf("\n\n");
	for (int i = 0; i < size; i++){
		printf("%c\n", arrPtr[i]);
	}
	return 0;
}

