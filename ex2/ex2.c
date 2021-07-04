// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Answer: It looks like both the parent and the child can write to the text file, but neither can read the
// file and display its contents.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void printfile(FILE * fp)
{
    int c;
    while(1) {
        c = fgetc(fp);
        if( feof(fp) ) {
            break;
        }
        printf("%c", c);
    }
}

int main(void)
{
    // Your code here 
    FILE * fp;
    fp = fopen ("text.txt", "r+");
    printf("text.txt before fork: ");
    printfile(fp);
    printf("\n");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, "This is the child here! ");
        printf("text.txt in the child: ");
        printfile(fp);
        printf("\n");
        fclose(fp);
    } else {
        fprintf(fp, "Parents rule! ");
        printf("text.txt in the parent: ");
        printfile(fp);
        printf("\n");
        fclose(fp);
    }    

    return 0;
}

