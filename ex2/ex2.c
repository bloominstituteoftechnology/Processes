// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

    //below is a file pointer:
    FILE *fp;
    //We use this pointer to store the result of calling fopen to the text.txt test file
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc <0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child here\n");
        char *child_str = "This is the child string!\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    } else {
        printf("parent here \n");
        char *parent_str = "This is the arent string!\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
        //can also do fprintf(fp, parent_str) here and in child
        //can also do parent_str[] instead of *parent_str
    }
  fclose(fp);
  return 0;
}
