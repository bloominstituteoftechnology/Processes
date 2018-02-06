// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently? it writes something like 桔獩椠⁳瑳楲杮琠潷吀楨⁳獩猠牴湩⁧湯e to the file

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * fp;
    fp = fopen ("text.txt", "w");
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        // char str1[] = "This is string one";
        // fwrite(str1, 1, sizeof(str1), fp);
        printf("hello, child is here\n");
    } else {
        char str2[] = "This is string two";
        fwrite(str2, 1, sizeof(str2), fp);
        printf("hello, parent is here\n");
    }
    fclose(fp);
    return 0;
}
