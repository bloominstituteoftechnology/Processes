// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * fp;
    fp = fopen("./text.txt", "w");
    fork();
    
    fprintf( fp, "this is written to the file by %d. \n", (int) getpid());
    //did it print sequentially because of the easy computation? 
    return 0;
}
