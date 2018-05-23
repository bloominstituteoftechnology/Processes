// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE  *fp;
    fp = fopen("text.txt", "w");

     int rc = fork();

     if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
     }  else if ( rc == 0) {
         printf("child process \n");
         char childStr[] = "this is the child string \n";
         fwrite(childStr, 1,  sizeof(childStr) - 1, fp);
     } else {
         printf("parent process \n");
         char parentStr[] = "this is the parent string \n";
         fwrite(parentStr, 1, sizeof(parentStr) - 1, fp);
     }
    
    return 0;
}
