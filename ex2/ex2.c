// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *f;
    f = fopen("text.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    int rc = fork();
    if (rc < 0) {    // fork failed; ercit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        char text[32] = "Child process.\n";
        fwrite(text, 1, sizeof(text), f);
        printf("Child process text: %s\n", text);
    } else {
        char text[32] = "Parent process.\n";
        fwrite(text, 1, sizeof(text), f);
        printf("Parent process text: %s\n", text);
    }
    // fclose(f);
    return 0;
}
