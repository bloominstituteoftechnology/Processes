// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("/text.txt", "r");
    char c; 
    while((c=fgetc(file))!=EOF) 
    { 
        printf ("%c", c); 
        // c = fgetc(file); 
    } 
  
    // int rc = fork();
    // if (rc < 0) {
    //     fprintf(stderr, "fork failed\n");
    // } else if (rc == 0) {
    //     printf("CHILD\n");
    //     printf("%c\n", file);
    // } else {
    //     printf("PARENT\n");
    //     printf("%c\n", file);
    
    // }
    return 0;
}

// If concurrent, the parent call will run first, but they will be two separate processes.
