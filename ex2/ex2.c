// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
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
    int f = fork();

    if(f < 0){
        printf("Fork failed!");
        exit(1);
    } else if(f == 0){
        printf("Child fork\n");
        fclose(f);
    } else {
        printf("Parent fork\n");
        char *parent_text = "This is the parent text.\n";
        fwrite(parent_text, sizeof(char), strlen(parent_text), f);
    }
    fclose(f);
    return 0;
}
