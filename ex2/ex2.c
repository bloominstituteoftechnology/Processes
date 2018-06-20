// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * file;
    file = fopen("text.txt", "w");
     
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("child\n");
        char child[] = "this is from the child\n";
        fwrite(child, 1, sizeof(child)-1, file);
    } else {
        printf("parent\n");
        char parent[] = "this is from the parent\n";
        fwrite(parent, 1, sizeof(parent)-1, file);
    }
    fclose(file);
    return 0;
}
