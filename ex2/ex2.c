// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp = fopen ("text.txt", "r");
    int rc = fork();
    char c;

    while((c=fgetc(fp))!=EOF){
        
        // if (rc < 0) {    // fork failed; exit
        // fprintf(stderr, "fork failed\n");
        // exit(1);
        // } else if (rc == 0) {    // child process satisfies this branch
        //     printf("Child\n");
        //     printf("%c",c);
        // } else {
        //     printf("Parent\n");
            printf("%c",c);
        // }
    }   
   
    fclose(fp);
    
    return 0;
}
