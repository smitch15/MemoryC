#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int isEqualSub(int param0, int param1){
	if (!(param0 - param1)) return 1;
	return 0;
}

int isEqualXOR(int param0, int param1){
	if (!(param0 ^ param1)) return 1;
	return 0;
}


int main(){
	int again = 1;
	char choice[BUFFER_SIZE];
	int arg0 = 0;
	int arg1 = 0;
	while(again){
		printf("\nPlease enter two integer values: ");
		scanf("%d %d", &arg0, &arg1);
		if (isEqualXOR(arg0, arg1)) printf("\nEqual");
		else printf("\nNot Equal");
		printf("\nPlease type 'exit' if you wish to quit: ");
		scanf("%s", choice);
		printf("\nchoice: %s", choice);
		printf("\nhex choice: %x \nhex 'e': %x\n", *choice, 'e');
		if (!(*choice - *"exit"))	again = 0;
	}
	return 0;
}
