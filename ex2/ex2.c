// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    file = fopen("text.txt", "r");
    char hold[100];
     while (fscanf(file,"%s ", hold)==1) 
        printf("%s ", hold); 
    fork();
    
    return 0;
}
