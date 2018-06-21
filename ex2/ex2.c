// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int readFile(FILE *file)
{
    char content = fgetc(file);

    while (content != EOF)
    {
        printf("%c", content);
        content = fgetc(file);
    }

    printf("\n");

    return 0;
}

int main(int argc, char* argv[])
{
    FILE *pFile = fopen(argv[1], "r");

    if (pFile == NULL){
        printf("INVALID FILE. CANNOT READ. \n");
        exit(0);
    }

    readFile(pFile);
    // fclose(pFile);

    // INITIALIZE CHILD PROCESS
    int childProcess = fork();

    if (childProcess < 0){ // the fork failed
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    }
    else if (childProcess == 0){
        printf("I AM THE CHILD PROCESS (pid: %d) \n", (int) getpid());
        printf("child process ~ %p \n", pFile);
    }
    else {
        printf("I AM THE PARENT PROCESS (pid: %d) OF CHILD %d \n", (int) getpid(), childProcess);
        printf("parent ~ %p \n", pFile);
    }
    
    return 0;
}
