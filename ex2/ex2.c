// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`?
    // Yes they both are able to because it is simply stored as an integer
// What happens when they are written to the file concurrently?
    // They both can write to the file, but mistakes happened when I ran it a few times.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");
    fprintf(file, "Hello, world!\n");

    int rc = fork();
    
    if (rc < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    if (rc == 0)
    {
        printf("Begin reading file on child process\n");
        while(1) {
            int c = fgetc(file);
            if( feof(file) ) { 
                break ;
            }
            printf("%c", c);
        }

        fprintf(file, "Hello from the child process\n");

        printf("Begin reading modified file (child)\n");

        while(1) {
            int c = fgetc(file);
            if( feof(file) ) { 
                break ;
            }
            printf("%c", c);
        }

        fclose(file);
    }
    if (rc > 0)
    {
        printf("Begin reading file on parent process\n");

        while(1) {
            int c = fgetc(file);
            if( feof(file) ) { 
                break ;
            }
            printf("%c", c);
        }

        fprintf(file, "Hello from the parent process\n");

        printf("Begin reading modified file (parent)\n");

        while(1) {
            int c = fgetc(file);
            if( feof(file) ) { 
                break ;
            }
            printf("%c", c);
        }

        fclose(file);
    }

    return 0;
}
