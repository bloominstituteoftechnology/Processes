// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// a. Yes, the child and parent can both access the file descriptor returned by the fopen().
// b. The parent seem to write first and then the child
// c. Not sure why there's an extra write in the text file to before the fork:

// Text File o/p:

// File write before fork 206
// Parent-File write 206
// File write before fork 206  <=== Why is this here?
// Child-File write 207

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    // FILE* fp;
    // FILE * fp;
    FILE *fp;

    fp = fopen ("text.txt", "w+");
    printf("Before forking pid: %d\n", (int) getpid());

    // fprintf(fp, "%s %s %s %s %d\n", "File", "write", "before", "fork", (int) getpid());
    fprintf(fp, "File write before fork %d\n", (int) getpid());
    printf("Another console print hello test\n");

    pid_t pid = fork();

    if (pid < 0) //fork failed
    {
        exit(1);
    } 
    else if (pid == 0) //child process
    {
        printf("AFTER forking CHILD pid: %d\n", (int) getpid());
        fprintf(fp, "%s %s %d\n", "Child-File", "write", (int) getpid());

    }
    else {
        printf("AFTER forking PARENT pid: %d\n", (int) getpid());
        fprintf(fp, "%s %s %d\n", "Parent-File", "write", (int) getpid());
    }
    fclose(fp);

    return 0;
}
