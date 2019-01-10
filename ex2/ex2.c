// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 

	FILE * fp;

	fp = fopen ("text.txt", "w+");
	int y = fork();

	if (y == 0){
		fprintf(fp, "%s %s %s %d", "We", "are", "in", 2019);
	} else{
		fprintf(fp, "%s %s %s %d", "We", "are", "in", 2020);
	}

	fclose(fp);
    
  return 0;
}
