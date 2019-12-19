// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char str[100];
    
    FILE *filePointer;
    filePointer = fopen("text.txt", "w");

    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(filePointer, "%s %s %s %s", "I", "am", "a", "child.\n");
        fclose(filePointer);
        printf("Child %d\n", (int) getpid());
    } else {
        fprintf(filePointer, "%s %s %s %s", "I", "am", "a", "parent.\n");
        fclose(filePointer);
        int wc = waitpid(rc, NULL, 0);
        printf("Parent %d of child %d\n", (int) getpid(), rc);
    } 
 
    if (filePointer == NULL) {
        printf("Error opening text file!");
        exit(1);
    }
    
    return 0;
}
