// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE* txt = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("child process\n");
        char childTxt[] = "Please Work\n";
        fwrite(childTxt, 1, sizeof(childTxt)-1, txt);
    } else {
        printf("parent process \n");
        char parentTxt[] = "Please Work, Child\n";
        fwrite(parentTxt, 1, sizeof(parentTxt), txt);
    }

    fclose(txt);
    return 0;
}