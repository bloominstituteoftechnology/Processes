// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fptr;
    fptr = fopen("text.txt","w");
    if (fptr == NULL) {
    	printf ("Unable to open/find the file, errno = %d\n", errno);
    	return 1;
	}
	
	int rc = fork();
	
	if (rc < 0) {    // fork failed; exit
        fprintf(fptr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        fprintf(fptr, "\n%s","new child process\n");
    } else {
        fprintf(fptr, "\n%s","parent process\n");
    }
    return 0;
}
