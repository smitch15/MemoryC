#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char buffer[100];
	// gets is dangerous because 
	// if the buffer is not big enough, it will keep storing values until
	// newline or EOF found. dangerous to store values passed allowed buffer
	// gets(string); // gives warning becuz its dangerous
	char str0[20] = "hello there";
	char str1[10] = "world";
	// memcpy (void * dest, void * src, int numBytes)
	memcpy(str0, str1, sizeof(str1));
	// strcpy (char * dest, char * src)
	puts(str0);
	printf("size of buffer: %lu\n", sizeof(buffer));
	// puts outputs a newline character at the end of a char array
	puts("please enter your name: ");
	fgets(buffer, sizeof(buffer), stdin);
	printf("Your name is %s", buffer);
}
