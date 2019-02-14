// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    // FILE *fopen(const char *filename, const char *mode);
    FILE *fp = fopen("text.txt", "w+");
    int s = fork(); 

    if(s == 0){
        fprintf(fp, "%s\n", "Inside child process....");
        printf("Inside child process\n");
    } else{
        fprintf(fp, "%s\n", "Inside parent process....");
        printf("Inside parent process....\n");
    }
    fclose(fp);
        
    return 0;
}
