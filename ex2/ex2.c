// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
     FILE *text = fopen("./text.txt", "a");  
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (child == 0) {
		char child_text[] = "\n\nHello, child here!\n\n";
		fwrite(child_text, sizeof(child_text), 1, text);
	} else {
		char parent_text[] = "\n\nI'm apparently a parent.\n\n";
		fwrite(parent_text, sizeof(parent_text), 1, text);
	}
	return 0;
}
