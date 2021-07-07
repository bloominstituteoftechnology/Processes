// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("./text.txt", "wb");
    printf("The file has been opened...\n");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char str[] = "The child hays hi.\n";
        fwrite(str, sizeof(char), strlen(str), fp);
    } else {
        char str[] = "The parent hays hi.\n";
        fwrite(str, sizeof(char), strlen(str), fp);
    }

    fclose(fp);
    return 0;
}

