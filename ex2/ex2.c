// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    int c;
    int y = 100;
    fp = fopen("text.txt","r");
    // while(1) {
    //     c = fgetc(fp);
    //     if( feof(fp) ) { 
    //         break ;
    //     }
    //     printf("%c", c);
    // }
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    } 
    while(1) {
        c = fgetc(fp);
        if( feof(fp) ) { 
            break ;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}
