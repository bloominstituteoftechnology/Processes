// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //need string.h for strlen

int main(void)
{
    
    // Your code here
    //file pointer declared to file open with (filename and mode set to "w")
    //start fork with int variable rc
    FILE* fp;

    fp = fopen("text.txt", "w");
    int rc = fork();

    //fork failed, then exit here w message.
    if (rc < 0) {
        fprintf(stderr, "fork has failed\n");
        exit(1);
    }
    //child process w arguments to the child pointer, size of the bytes per character (sizeof(char)), string length of child pointer and start fp process
    else if (rc == 0) {
        char *chldptr = ("child process here.\n");
        fwrite(chldptr, sizeof(char), strlen(chldptr), fp);

    }
    //parent process w arguments to the parent pointer, size of the bytes per char (sizeof(char)), string length of parent pointer and start fp process
    //wait added to allow child process to be printed first(removed as well to test)
    else {
        char *parptr = ("from parent process.\n");
        fwrite(parptr, sizeof(char), strlen(parptr), fp);
    }

        
    

    fclose(fp);
    return 0;

}
