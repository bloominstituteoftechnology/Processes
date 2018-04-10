// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// both the parent and the child cannot access the file descriptor returned by fopen()
// when they are written to the file concurrently the parent process takes precedence over the child process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 

    // open text.txt file using fopen()
	FILE *fp;
	int c;

	printf("opening file text.txt\n");

	fp = fopen("text.txt", "r");

    // calls fork() to create a new process

    int rc = fork();

    if (rc < 0) {
    	printf("fork failed\n");
    	exit(1);
    } else if (rc == 0) {
    	printf("CHILD EXECUTING:\n");
    	while(1) {
			c = fgetc(fp);
			if (feof(fp)) {
				printf("\n");
				break;
			}
			printf("%c", c);
		}
		fclose(fp);
    } else {
    	printf("PARENT EXECUTING:\n");
    	while(1) {
			c = fgetc(fp);
			if (feof(fp)) {
				printf("\n");
				break;
			}
			printf("%c", c);
		}
		fclose(fp);
    }
    
    return 0;
}
