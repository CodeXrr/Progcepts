#include <stdio.h> 

int main(void) {
	int value1 = 4;
	int value2 = 8; 

	printf("value1 @ (%p): %d\n", &value1, value1); 
	printf("value2 @ (%p): %d\n", &value2, value2); 
}
