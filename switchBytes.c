#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a C function: void ReverseInPlace( char *String )that reverses a null terminated character string, as in:  
 char S[] = “ABC”;   Reverse(S);   printf( “%s”, S );  //  should print CBA
*/

void ReverseInPlace(char *string){
	int size = strlen(string);
	char *newstr = (char *) malloc(size);
	for (int i = 0; i < size; i++){
		*newStr = string[size-i-1];
		newStr++;
	}
	free(newstr);
}

