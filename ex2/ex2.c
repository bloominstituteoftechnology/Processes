// Write a program that opens the text.txt  file (with the `open()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `open()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// function to read the file
void readTheFile() {
    int ch;
    FILE *fp;
    fp = fopen("/Users/ryansherrill/Desktop/Lambda/Section 2/Processes/ex2/text.txt", "r");
    ch = getc(fp);
    while (ch != EOF) {
        putchar(ch);
        ch = getc(fp);
    }
    fclose(fp);
}

int main(int argc, char* argv[])
{
    int x = 100;
    printf("Hello from Main (pid: %d)\n", (int) getpid());
    printf("Main says: x = %d \n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x -= 50;
        printf("Hello from Child (pid: %d)\n", (int) getpid());
        printf("Child says: x = %d \n", x);
        readTheFile();
        
    } else {
        x += 25;
        printf("Hello from Parent (pid: %d)\n", (int) getpid());
        printf("Parent Process says: x = %d \n", x);
        readTheFile();
    }
    printf("Final check says: x = %d \n", x);
    return 0;
}
