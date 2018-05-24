// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int forker()
{
    printf("hello world (pid:%d) \n", (int) getpid());
    int rc = fork();
    if (rc < 0) 
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0 )
    {
        printf("hello, I am child (pid:%d\n", (int) getpid());
     
            // FILE *fp;
            // int c;

            // fp = fopen("text.txt", "r");

            // while(1)
            // {
            //     c = fgetc(fp);
            //     if ( feof(fp) ) 
            //     {
            //         break;
            //     }
            //     printf("%c", c);
            // }



    }
    else
    {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        // fopen("text.txt", "r");
        //         FILE *fp;
        //         int c;

        //         fp = fopen("text.txt", "r");

        //         while(1)
        //         {
        //             c = fgetc(fp);
        //             if ( feof(fp) ) 
        //             {
        //                 break;
        //             }
        //             printf("%c", c);
        //         }
            
    }
}

FILE *fopen(const char *filename, const char *mode);


int main(int argc, char* argv[])
{
    // Your code here 
    forker();
    
    FILE *fp;
    int c;

    fp = fopen("text.txt", "r");

    while(1)
    {
        c = fgetc(fp);
        if ( feof(fp) ) 
        {
            break;
        }
        printf("%c", c);
    }
    
    forker();


    
    return 0;
}
