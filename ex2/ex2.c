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
    fp = fopen("./text.txt", "r");
    char c[30];
    int rc = fork();
    if (rc < 0) {
        printf("error");
        exit(1);
    } else if (rc == 0) {
        printf("child\n");
        fgets(c, 30, fp);
        printf("%s\n", c);
    } else {
        printf("parent\n");
        fgets(c, 30, fp);
        printf("%s\n", c);
    }

    return 0;
}
