// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    char buffer[255];

    fp = fopen("text.txt", "r");

    pid_t rc = fork();

    if (rc == 0)
    {
        fgets(buffer, 255, fp); //read one line
        printf("Child read: %s", buffer);
    }
    else
    {
        sleep(1);
        printf("parent woke up\n");

        fgets(buffer, 255, fp);
        printf("parent read: %s", buffer);
    }
    
    return 0;
}
