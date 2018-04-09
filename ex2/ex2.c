// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    int c;

    fp = fopen("text.txt", "r+");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char str[] = "Child string here. Trying to do great things.\n";
        fwrite(str, 1, sizeof(str), fp);
    } else {
        char str2[] = "Parent string here. Trying to do great things.\n";
        fwrite(str2, 1, sizeof(str2), fp);
    }


    fclose(fp);
    return 0;
}
