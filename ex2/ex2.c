// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fd = fopen("text.txt", "r+");
    pid_t pid = fork();
    if (pid < 0) {
        printf("Forking failed.");
    } else if (pid == 0) {
        printf("Hello from child process.\n");
        fprintf(fd, "%s", "Child");
        fclose(fd);
        FILE *fp = fopen("text.txt", "r");
        while (1) {
            int c = fgetc(fp);
            if (feof(fp)) {
                break;
            }
            printf("%c", c);
        }
        printf("\n");
        fclose(fp);
    } else {
        printf("Hello from parent process.\n");
        fprintf(fd, "%s", "Parent");
        fclose(fd);
        FILE *fp = fopen("text.txt", "r");
        while (1) {
            int c = fgetc(fp);
            if (feof(fp)) {
                break;
            }
            printf("%c", c);
        }
        printf("\n");
        fclose(fp);
    }
    return 0;
}

