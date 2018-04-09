// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    // FILE* fopen(text file here)
    FILE* fp;
    fp = fopen("text.txt", "a");
    // int rc(run commands?) fork()
    int rc = fork();
    if (rc < 0) {
    // file print = fprintf()
    fprintf(stderr, "What the Fork!!!\n");
    exit(1);
    // else if child process print the process
    // write   
    } else if (rc == 0) {
        printf("wee little one\n");
        char child_str[] = "wee little string!!!\n";
        fwrite(child_str, 1, sizeof(child_str), fp);
    // else print parent
    // write
    } else {
        printf("big parent\n");
        char parent_str[] = "big giant string!!\n";
        fwrite(parent_str, 1, sizeof(parent_str), fp);
    }
    fclose(fp);
    
    
    return 0;
}
