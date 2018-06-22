// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    int c;
    FILE * fp;
    fp = fopen("text.txt", "r");
    int rc = fork();
    if (rc < 0) { 
        fprintf(stderr, "fork failed\n");
        exit(1);
        } 
    else if (rc == 0) {  
        printf("child\n");
        while(1) {
            c = fgetc(fp);
            if( feof(fp) ) { 
            break ;
        }
        printf("%c", c);
    }

    } else {
        printf("parent\n");
        while(1) {
        c = fgetc(fp);
        if( feof(fp) ) { 
            break ;
        }
        printf("%c", c);
    }

    }
    fclose(fp);
    return 0;
}
