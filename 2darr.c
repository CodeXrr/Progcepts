#include <stdio.h>
#include <string.h>

#define KW_COUNT 4
#define KW_SIZE_MAX 32

void print(char arr[KW_COUNT][KW_SIZE_MAX]) {
	char *ptr;

	for (int i=0; i < KW_COUNT; i++) {
		ptr = (char *) &arr[i];
		printf("ptr: %s\n", ptr);
		printf("strcmp(): %d\n", (strcmp(ptr, "char")));
	}
}

int main(void) {
	char arr[][KW_SIZE_MAX] = {"int", "char"};

	print(arr);
}
