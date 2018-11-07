// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
	FILE *fp;

	fp=fopen("text.txt", "w+");   //w is write mode

	pid_t pid;
    	pid = fork();	

	if(pid==0){
    		fprintf(fp, "This is child process\n"); //this sentence is written to the text.txt file by accessing the file descriptor returned by fopen
	}
    	else{
		fprintf(fp, "This is parent process\n"); ////this sentence is written to the text.txt file by accessing the file descriptor returned by fopen
    	}

	fclose(fp);  //closes the stream which is a pointer to the File object.
    	return 0;
}

