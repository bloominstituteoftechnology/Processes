// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void openFile() {
    FILE * fp;
    int c;
    fp = fopen("text.txt", "r");
    if (fp) {
        while ((c = getc(fp)) != EOF)
            putchar(c);
            printf("\n");
        fclose(fp);
    }
}

int main(int argc, char* argv[])
{
    // Your code here 
    openFile();
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // openFile();
        printf("Child: success with opening file\n"); // Does not have access to openFile() or the parent process aside from fork
    } else {
        printf("Parent: success with opening file\n");
    }
    return 0;
}
