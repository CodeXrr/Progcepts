#include <stdio.h>

int main(int argc, char *argv[]) {
	for(int i=0; i < 56; i++)
		printf("%d mod 16: %d\n", i, (i%16)); 
}	
