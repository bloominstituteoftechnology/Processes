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
    int rc = fork();

    fp = fopen("text.txt", "r");

    if (rc < 0) {
        fprintf(stderr, "Child process failed.\n");
        exit(1);
    } else if (rc == 0) {
        char text[30] = "This is child process.\n";
        fwrite(text, 1, sizeof(text), fp);
        printf("Text from child process: %s\n", text); //accesses text file, writes its own text with no affect from parent
    } else {
        char text[30] = "This is parent process.\n";
        fwrite(text, 1, sizeof(text), fp);
        printf("Text from parent process: %s\n", text); //accesses text file, writes its own text with no affect from child
    }
    fclose(fp);

    return 0;
}
