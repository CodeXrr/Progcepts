#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 512 // Displays 32 lines.

// Dumps raw memory in hex byte and printable split format
void dump(const unsigned char *data_buffer, const unsigned int length) {
	unsigned char byte; 
	unsigned int i, j; 
	int loopcnt = 0; 
	for(i=0; i < length; i++) {
		byte = data_buffer[i];
		printf("%02x ", data_buffer[i]); // Display byte in hex.

		if(((i%16)==15) || (i==length-1)) {
		
			for(j=0; j < 15-(i%16); j++) 
				printf("  "); 
			printf("| "); 
			for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
				if(loopcnt == 0)
					printf("ENTERED LOOP: j == %d\n", (i-(i%16))); 
				printf("j(%d) <= i(%d)\n", j, i);  
				
				byte = data_buffer[j];
				if((byte > 31) && (byte < 127)) // Inside print range
					printf("%c", byte); 
				else
					printf("."); 
				loopcnt++; 
			}
		printf("\n"); // End of line. Line is 16 bytes.
		} //end if
	}

	
}

int main(int argc, char *argv[]) {
	char rbyte = 0;
	// Create a Usage-implementation file. Right now,
	// usage is simple. But a more in depth program that takes 
	// alot of diffrent options should be put into a seperate file.
	if(argc < 2) {
		printf("Usage: %s <file2dump>\n", argv[0]); 
		exit(0); 
	}

	unsigned char file_buffer[BUFFER_SIZE]; 

	int fd = open(argv[1], O_RDONLY); 
	if(fd == -1) {
		printf("[!!] ERROR | opening \'%s\'\n", argv[1]); 
		exit(-1); 
	}
	
	char abuf[64]; 
	for(int i=0; i < 64; i++) 
		abuf[i] = 'A';

	while(read(fd, file_buffer, BUFFER_SIZE) == BUFFER_SIZE) {
		dump(file_buffer, BUFFER_SIZE);
		printf("enter to continue... "); 
		scanf("%c", &rbyte); 
	}
	dump(abuf, 64); 
	close(fd); 


}
