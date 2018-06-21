// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * test;
    test = fopen("text.txt", "r");
    fprintf(test, "%s %s %s %d", "Our", "file", "is \n", test);

    int rc = fork();
    if(rc < 0) {
        //do nothing
        exit(1);
    } else if (rc == 0) {
        printf("My value is \n", test);
    }else {
        prinf("As the parent my value is  \n", test);
    }
    fclose(test);
    
    return 0;
}
