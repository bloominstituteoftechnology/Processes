// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if (rc == 0) {
        printf("child process\n");
        char *child = "This is the child\n";
        fwrite(child, sizeof(char), strlen(child), fp);
    } else {
        printf("parent process\n");
        char *parent = "This is the parent\n";
        fwrite(parent, sizeof(char), strlen(parent),fp);
    }
    fclose(fp);
    
    return 0;
}
