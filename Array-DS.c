#include <stdio.h>
#include <stdlib.h>
	
# define  ARRAY_SIZE = 5;
	
void populate2DArray();

void populate2DArray(){

	/*statically declare 2d array*/
	int arr0[10][10] = {{0}};
	/*or*/
	int x=10,y=10;
	int arr1[x][y];
	for (x=0; x<10; x++){
		for (y=0; y<10; y++){
			arr0[x][y] = 0;
		}
	}

	/*dynamically declare 2D array */
	int* arr3 = (int *) malloc(sizeof(int));
	
	printf("%p\n", arr3);
	for (x = 0; x < 10; x++){
		arr3[x] = 0;
		printf("%d\n", arr3[x]);
	}
	free(arr3);
}

int main(){
	populate2DArray();
	return 0;
}
