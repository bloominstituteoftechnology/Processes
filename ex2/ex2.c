// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *text = fopen("text.txt", "r+");
    int rc = fork();
    if (rc < 0) 
    {
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(text, "hello");
    }
    else
    {
        waitpid(rc, NULL, 0);
        fprintf(text, "goodbye");
        fclose(text);

        // Open the file to print it while the Docker container is still running
        FILE *fp = fopen("text.txt", "r");
        int c;
        while (1)
        {
            c = fgetc(fp);
            if (feof(fp))
            {
                break;
            }
            printf("%c", c);
        }
        return 0;
    }
}
