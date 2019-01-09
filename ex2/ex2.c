// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> // `waitpid` needs to be included separately

int main(void)
{
    FILE * fp;
    char c;

    int rc = fork();

    if (rc == 0) { // child process
        // append
        fp = fopen ("text.txt", "w");

        if (fp == NULL) {
            printf("Could not open file.");
            return -1;
        }

        fprintf(fp, "%s %s %d%c%c", "Child is writing.", "Child's pid is", getpid(), '.', '\n');

        fclose(fp);
    } else { // parent process
        // wait for child
        int wc = waitpid(rc, NULL, 0);

        // append
        fp = fopen ("text.txt", "a");

        if (fp == NULL) {
            printf("Could not open file.");
            return -1;
        }

        fprintf(fp, "%s %s %d%c %s %d%c%c", "Parent is writing.", "Parent's pid is", getpid(), '.', "Its child's pid was", rc, '.', '\n');

        fclose(fp);

        // read
        fp = fopen ("text.txt", "r");

        if (fp == NULL) {
            printf("Could not open file.");
            return 1;
        }

        while(1) {
            c = fgetc(fp);
            if (feof(fp)) {
                break;
            }
            printf("%c", c);
        }

        fclose(fp);
    }

    return 0;
}
