// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    char str[7];
    FILE * fp;
    fp = fopen("text.txt", "r");
    int cp = fork();
    if (cp < 0) {
        printf("Fork failed.");
        exit(1);
    } else if (cp == 0) {
        fscanf(fp, "%s", str);
        printf("File content in child: %s\n", str);
    } else {
        fscanf(fp, "%s", str);
        printf("File content in parent: %s\n", str);
    }
    
    return 0;
}
