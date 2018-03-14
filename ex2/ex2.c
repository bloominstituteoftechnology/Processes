// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp = fopen("text.txt", "r+");
    int child = fork();
    char c;

    if (child < 0)
    {
        printf("Unable to fork a child\n");
        exit(1);
    }
    else if (child == 0)
    {
        c = fgetc(fp);
        fprintf(fp, "%s", strcat(c, "NewChild"));
        printf("Child fork created\n");
    }
    else
    {
        //fprintf(fp, "%s newParent", *fp);
        printf("I am a parent!\n");
    }
    wait(NULL);
    //reading the .txt file
    while(1)
    {
        c = fgetc(fp);
        if(feof(fp))
        {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}
