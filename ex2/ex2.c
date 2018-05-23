// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int c;
    FILE *fp;
    int frk = fork();
    fp = fopen("text.txt", "r+");

    if (frk != 0){
        fprintf(fp, "this is some stuff written by the child");
    } else {
        while ((c = getc(fp)) != EOF){
            printf("%c", c);
        }
        fclose(fp);
    }
    
    return 0;
}
