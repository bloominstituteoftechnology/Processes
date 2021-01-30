// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

//It would seem that the parent and child CAN actually both access the file descriptor simulatenously. However, the order in which they write to the file may be non-deterministic.
//In my testing, the parent process seems to write into the file first.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    int c;
    printf("Ex2 is executing (at least)\n");
    fp = fopen("./text.txt", "w");
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        fprintf(stderr, "You forked up!\n");
        exit(1);
    } else if (responseFromFork == 0) {
        printf("As the child, yo I gotta write");
        fprintf(fp, "I'm the child process, and I wish I were an orphan.\n");
    } else {
        printf("As the parent, imma try to write.");
        fprintf(fp, "I'm the parent process, and I got edited earlier, deal with it.\n");
    }
    
    return 0;
}
