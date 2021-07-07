// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp; 
    fp = fopen("text.txt", "w+");
    fputs("We are in 2018\n", fp);
    // fclose(fp);
    int rc = fork();
    printf("rc: %d\n", rc);

    if (rc < 0) {
        printf("fork failed\n");
    } else if (rc == 0) {
        printf("Child process with pid %d\n", (int) getpid());
        // fp = fopen("text.txt", "r");
        // char * c = "New line\n";
        fputs("We will be in 2019\n", fp);
        // fwrite(c, sizeof(char), strlen(c), fp);
        // int c;
        // while(1) {
        //     c = fgetc(fp);
        //     if( feof(fp) ) {
        //         break;
        //     }
        //     printf("%c", c);
        // }
        // fclose(fp);
        // printf("\n");
    } else {
        printf("Parent process with pid %d\n", (int) getpid());
        // char * c = "But we are still in 2019\n";
        fputs("But we are still in 2018\n", fp);
        // fwrite(c, sizeof(char), strlen(c), fp);
    }
    return 0;
}
