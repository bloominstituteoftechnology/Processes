// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp; // --> Create a pointer to a file

    fp = fopen("text.txt", "w"); // --> since it already exists the txt file will be erased and creates a new one

    fprintf(fp, "%s %s %s %s\n", "We", "can", "do", "it");

    if (fp) {
        int rc = fork();

        if (rc < 0) {
            fprintf(stderr, "fork failed || but a spoon might work\n");
            exit(1);
        } else if (rc == 0) { // --> If child process receives the 0 that it expects...
            fprintf(fp, "%s %s %s\n", "Yes", "we", "can");
            printf("Child (pid: %d)\n", (int) getpid());
            printf("rc == 0\n");
        } else {
            fprintf(fp, "%s\n", "Parent");
            printf("Parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        }

        fclose(fp); // --> Close the file
        printf("File has been closed :D\n");
    }
    
    return 0;
}

/*
    - When written concurrently it seems the parent writes the "Parent" (line 29) 
        - Then the child process comes second writing what it was assigned
        - Obviously line 16 runs first before either attempt

    - They both can access the file given by fopen()
*/
