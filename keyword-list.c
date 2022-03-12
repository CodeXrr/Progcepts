#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define KW_COUNT 4
#define KW_MAX_SIZE 32
 

void *keyword_alloc(int max_size) {
	char *keyptr; 

	keyptr = (char *) malloc(max_size); 
	if(keyptr == NULL) {
		printf("[!!] ERROR in keyword-alloc() | Allocating memory for string.\n"); 
		exit(-1); 
	}

	return keyptr; 
}

int add_keyword(char *key_word, char *dest) {
	strcpy(dest, key_word); 
}

int main(void) {
	char str_arr[2][6] = { "int", "char" }; 

	printf("keyword: %s\n", str_arr[0]); 

}


