// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 

    // FILE * fp;
    // int c;
    // fp = fopen("text.txt", "r");
    // while(1)
    // {
    //     c = fgetc(fp);
    //     if(feof(fp))
    //     {
    //         break;
    //     }
    //     printf("%c", c);
    // }
    

    // fork();

    // fp = fopen("text.txt", "r");
    // while(1)
    // {
    //     c = fgetc(fp);
    //     if(feof(fp))
    //     {
    //         break;
    //     }
    //     printf("%c", c);
    // }
    
    

    
    FILE * fp;
    int c;

    int rc = fork();
    
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0)
    {
        fp = fopen("text.txt", "r");
        while(1)
        {
            c = fgetc(fp);
            if(feof(fp))
            {
                break;
            }
            printf("%c", c);
        }
        printf("child here (pid: %d)\n", (int) getpid());
    }
    else
    {
        fp = fopen("text.txt", "r");
        while(1)
        {
            c = fgetc(fp);
            if(feof(fp))
            {
                break;
            }
            printf("%c", c);
        }
        printf("parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
