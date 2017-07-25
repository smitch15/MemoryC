#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	// assign string literal
	char str[] = "abc";
	// declare char pointer
	char *str2;
	
	// cpy str content into str2 array
	strcpy(str2, str);
	printf("str1: %s, str2: %s\n", str, str2);
	
	// print char and hex values of str
	printf("size of '%s': %lu\n", str, sizeof(str)); 
	for (int i = 0; i < sizeof(str); i++){
		printf("char is: %c, hex is: %p\n", str[i], str[i]);
		
	}

	// print char and hex values of str2
	printf("size of '%s': %lu\n", str2, sizeof(str2)); 
	for (int i = 0; i < sizeof(str2); i++){
		printf("char is: %c, hex is: %p\n", str2[i], str2[i]);
		
	}
	return 0;
}
