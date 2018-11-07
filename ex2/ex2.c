// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    // Your code here 
	FILE* fp; 
	// Open file in Read mode 
	fp = fopen("text.txt", "w"); 

	// data in file: geeksforgeeks 

	// for (int i=0; i<10; i++){
    //     fprintf(fp, "Noah\n", i);
    // }
 

    // return 0;

    if (pid < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {    // child process satisfies this branch
        
       fprintf(fp, "car\n");
    } else {
        
        fprintf(fp, "dog\n");
    }
    fclose(fp); // Close File after Reading 
    return 0;
}
