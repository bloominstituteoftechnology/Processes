// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp;
		int c;
		char *str;

    fp = fopen("text.txt", "w+");
    int rc = fork();

    if (rc < 0)
    {
    	fprintf(stderr, "fork failed!\n");
    	exit(1);
    }
    else if (rc == 0)
    {
    	printf("Hello child here (pid: %d)\n", (int)getpid());
    	str = "Child process";
    	fwrite(str, 1, strlen(str), fp);
    }
    else
    {
    	printf("Hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    	str = "Parent process";
    	fwrite(str, 1, strlen(str), fp);
    }

    fclose(fp);
    return 0;
}
