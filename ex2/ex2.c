// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE * fp;
	fp = fopen ("text.txt", "w+");

	int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process here\n");
		char *child_str = "this is the child string!\n";
		fwrite(child_str, 1, strlen(child_str), fp);
    } else {
		printf("parent process here\n");
		char *parent_str = "this is the parent string!\n";
		fwrite(parent_str, 1, strlen(parent_str), fp);
	}

	fclose(fp);
    
    return 0;
}
