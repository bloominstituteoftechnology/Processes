// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * file;
    file = fopen("text.txt", "r+");

    if (fork() == 0){
        fprintf(file, "%s", "child!");
        printf("child: %d\n", fileno(file));
    }else{
        fprintf(file, "%s", "parent");
        printf("parent %d\n", fileno(file));
    }
    fclose(file);
    return 0;
}


// A: Yes the child and the parent can access the file descriptor returned by fopen and they both get written in!