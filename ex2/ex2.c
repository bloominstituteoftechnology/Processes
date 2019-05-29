// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
// Yes; they both seem to repeat, where you'd only expect the code after the fork to complete.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("text.txt", "w+");

    fprintf(fp, "Hello from parent");

    int f = fork();
    if (f < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }

    fprintf(fp, "Hello from child");

    fclose(fp);

    return 0;
}
