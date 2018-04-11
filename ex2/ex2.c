// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Nobody here but us chickens...\n ");
        exit(1);
    } 
    else if (rc == 0)
    {
        printf("child process\n");
        char *child_str = "Insert child string here...\n";
        fwrite(child_str, sizeof(char), sizeof(child_str), fp);
    }
    else
    {
        printf("parent process\n");
        char *parent_str = "Insert parent string here...\n";
        fwrite(parent_str, sizeof(char), sizeof(parent_str), fp);
    }
    
    return 0;
}
