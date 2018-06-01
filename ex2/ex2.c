// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here
     int c;
    FILE * fp;
    fp = fopen("text.txt", "r");
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
        } 
    else if (rc == 0) {  
        printf("child\n");  // child process satisfies this branch
        char child_str[] = "This is child string!\n";
        fwrite(child_str, 1, sizeof(child_str) - 1, fp);
    } else {
        printf("parent\n");
        char parent_str[] = "This is parent string!\n";
        fwrite(parent_str, 1, sizeof(parent_str) - 1, fp);
    }
    fclose(fp);
 
  return 0;
}
