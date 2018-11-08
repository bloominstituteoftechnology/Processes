// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? A: Yes     What happens when they are written to the file concurrently?: It works. Mine seemed to write parent first and child second with how I implemented it.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *pFile;
    pFile = fopen("text.txt", "a+");

    if (pFile != NULL)
    {
        int f = fork();
        if (f > 0) 
        {
            char *pText = "I am the parent file and printed Parent text. Go to your room!";  
            fprintf(pFile, "Some text: %s\n", pText);
            fclose(pFile);
        }
        else if (f == 0) 
        {
            char *cText = "I am the child file and printed child text. YeetSw4gxxx69er is my pronoun"; 
            fprintf(pFile, "Some text: %s\n", cText);
            fclose(pFile);
        }
        else 
        {
            fprintf(pFile, "doubt this should work\n");
            fclose(pFile);
        }
    }
    else
    {
            printf("Could not open the file\n");
    }
    
    return 0;
}

