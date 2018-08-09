// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("hello world (pid: %d)\n", (int) getpid());
    FILE *file_descriptor;
    char filename = "text.txt";
    char mode = "r+";
    file_descriptor = fopen("text.txt", "r+");

    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        
        printf("hello, child here (pid: %d) \n", (int) getpid());
        for(int i = 0; i < 10;i++){
         fprintf (file_descriptor, "This is child's line %d\n",i + 1);
        }
        /* close the file*/  
        fclose (file_descriptor);
    } else {
        
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        /* write 10 lines of text into the file stream*/
        for(int i = 0; i < 10;i++){
         fprintf (file_descriptor, "This is parent's line %d\n",i + 1);
        }
        /* close the file*/  
        fclose (file_descriptor);
    }
    //fclose (file_descriptor);
    return 0;
}
