// Write a program that opens the text.txt  file 
// (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. 
// Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written 
// to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen ("text.txt", "r+");

    int rc = fork();

    if (rc < 0) {
    	exit(1);
    } 


    
    int pid;
    char name[10];
    if (rc == 0){
    	    int fd = fileno(fp);
    	printf("Child:\nFile Descriptor: %d\n", fd);
    	fprintf(fp, "Child PID:%d\n", (int)getpid);
    } else {
    	    int fd = fileno(fp);
    	printf("Parent:\nFile Descriptor: %d\n", fd);
    	fprintf(fp, "Parent PID:%d\n", rc );
    }

    printf("closed = %d\n", fclose(fp));
    return 0;
}
