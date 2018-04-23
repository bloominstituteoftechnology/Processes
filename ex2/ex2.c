// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen("text.txt", "w");

		int rc = fork();

		if (rc < 0) {
		  fprintf(stderr, "Child process failed.\n");
			exit(1);
		} else if (rc == 0) {
		   char str1[] = "This is the child process\n";
			 fwrite(str1, 1, sizeof(str1), fp);
			} else {
			 char str2[] = "This is the parent process\n";
			 fwrite(str2, 1, sizeof(str2), fp);
			}

			fclose(fp);
    return 0;
}
