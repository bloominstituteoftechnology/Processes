// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // we are forking and having both parent and child write to the same file...
    // declare empty file descriptor
    FILE  *fp;
    // (name of the file, "w" = write permissions)
    // giving us permission to write to the file behind the file discriptor
    fp = fopen("text.txt", "w");
    int rc = fork();
    // error handling
    if (rc < 0) {
        fprintf(stderr, "fork FAILED!!!\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process\n");
        // here it is declared as a pointer, (so sizeof would get the size of the pointer not the string.)
        // pointer is more typical when denoting a string, import the string header above: <string.h>, then do string length of child string.
        char *child_str = "this is the child string...\n";
        fwrite(child_str, 1, strlen(child_str), fp);
        // or, using sizeof we can get the siz of the array, but we need to minus 1 not print null at the end
        // char child_str[] = "this is the child string...\n";
        // fwrite(child_str, 1, sizeof(child_str) - 1, fp);
    } else {
        // as a side not, best practice we would specify the order that we want these to print
        // to the file: prent first or child first?
        // if we wanted to have the parent print afer the child
        // int wc = waitpid(rc);  //with out this it would switch about 50-50 who's frst.
        // but we don't care about the order for this assignment so...w/e
        printf("Parent process\n");
        char *parent_str = "this is the parent string...\n";
        fwrite(parent_str, 1, strlen(parent_str), fp);
    }
    // close file pointer = resource leak.
    fclose(fp);

    return 0;
}
