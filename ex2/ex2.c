// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{ 
    FILE *fp = fopen("text.txt", "r+");
    fprintf(fp, "%s %s %s %s", "Text", "file", "is", "open\n");
    int rc = fork();
    fprintf(fp, "%s %s %s %s", "Child", "has", "accessed", "file\n");

    while(1){
        int c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    return 0;
}
