// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 

    FILE *fp; //Point file to fp, proper syntax
    int c; // ^^

    fp = fopen("text.txt","r+"); //fopen()
    int rc = fork(); 

    if(rc < 0) {
        fprintf(stderr, "The fork was a failure now exiting\n");
        exit(1);
    } else if(rc == 0) {
        fprintf(fp, "\n%s", "This is the child's string\n");
    } else {
        fprintf(fp, "\n%s","This is the parent's string\n");
    }

    fclose(fp);

    return 0;
}
