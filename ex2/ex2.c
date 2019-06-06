// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here 
    FILE *file;
    printf("Hello there, before we call fork(), this is our processID is: (pid: %d) \n", (int)getpid());
    file = fopen("text.txt", "a+");
    while (1)
    {
        int c = fgetc(file);
        if (feof(file))
        {
            break;
        }
        printf("%c", c);
    }

    int rc = fork();

    if (rc < 0)
    {
        printf(stderr, "\nForking failed \n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("\nWe are now attempting to wait for child process to finish. . . \n");
        file = fopen("text.txt", "a+");
        printf("\nHello there, if rc==0, this is our child processID is: (pid: %d) \n", (int)getpid());
        // printf("This is the childs value for file (opening a file): %d \n", file);
        file = fopen("text.txt", "a+");
        fprintf(file, "%s %s %s %s %s %s %s", "\nWe", "are", "writing", "in", "the", "child", "process\n");
        fclose(file);
        file = fopen("text.txt", "a+");
        while (1)
        {
            int c = fgetc(file);
            if (feof(file))
            {
                break;
            }
            printf("%c", c);
        }
        fclose(file);
    }
    else
    {
        // int wc = waitpid(rc, NULL, 0);
        printf("\nOur child has now finished executing, we are back in Parent process with PID: (%d)\n", (int)getpid());
        file = fopen("text.txt", "a+");
        fprintf(file, "%s %s %s %s %s %s %s", "\nWe", "are", "writing", "after", "the", "child", "process\n");
        fclose(file);
        // printf("This is the childs value for file (opening a file): %d \n", file);
        file = fopen("text.txt", "a+");
        while (1)
        {
            int c = fgetc(file);
            if (feof(file))
            {
                break;
            }
            printf("%c", c);
        }
        fclose(file);
    }
    
    return 0;
}
