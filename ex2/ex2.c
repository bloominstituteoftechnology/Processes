// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int readFile()

{
    FILE *fp;
    fp = fopen("text.txt", "r");
    char singleLine[150];
    while (!feof(fp))
    {
        fgets(singleLine, 150, fp);
    }
    puts(singleLine);
    fclose(fp);
    return (0);
}

int writeFile()

{
    FILE *fp;
    fp = fopen("text.txt", "w");
    fprintf(fp, " i love lambda school too much \n");
    fclose(fp);
    return (0);
}

int main(int argc, char *argv[])
{
    printf(" getpid is %d \n", (int)getpid());
    //writeFile();
    readFile();

    //////////////////////////////
    int rc = fork();
    printf("*****(rc:%d) \n", rc);
    /////////////////////////////////////
    if (rc < 0)
    {
        fprintf(stderr, " fork failed \n");
    }
    else if (rc == 0)
    {
        printf("=======> child here (pid:%d)\n", (int)getpid());
        writeFile();
        // readFile();
    }
    else
    {

        printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
        writeFile();
        //readFile();
    }

    return 0;
}
