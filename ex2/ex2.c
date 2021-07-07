// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "w"); // Open text.txt, 'w' sets text.txt to an empty file we can write in

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process here\n");
        char *child_str = "This is child string!\n";
        fwrite(child_str,  // child_str is a pointer to the array of elements to be written
        sizeof(char),     // sizeof(char) is the size in bytes of each element to be written
        strlen(child_str), // strlen(child_str) is the number of elements, each one with a size of size bytes from sizeof(char)
        fp);                //fp is the pointer to a file object that we are executing/writing in, in this case it is fp: aka text.txt
    } else {
        printf("parent process here\n");
        char *parent_str = "This is parent string!\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    }
    fclose(fp);
    return 0;
}
