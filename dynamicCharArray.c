#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *buf = (char *) malloc(sizeof("Hello World\n"));
	sprintf(buf, "Hello World\n");
	printf("%s\n", buf);	
	return 0;
}

