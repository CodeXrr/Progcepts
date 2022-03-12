#include <stdio.h>
#include <string.h>

static void make_list(char *p[])
{
	p[0] = "int";
	p[1] = "char";
}
char cmpre(char *word, char *keylist, int keylist_sz) {
	if(strcmp(word, (&keylist[0])) == 0) 
		return 1;
	else
		return 0;
}

int main(void) {
	char word_buffer[32];
	strcpy(word_buffer, "int"); 

	char *words[2];
	make_list(words);

	if(cmpre(word_buffer, &words, 4))
		printf("FOUND MATCH\n"); 
	else
		printf("did not FIND MATCH\n"); 
}
