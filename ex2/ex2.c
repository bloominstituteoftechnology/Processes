// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char file[] = "text.txt";

    fp = fopen(file, "r");

    int descriptor = fileno(fp);

    printf("File descriptor: %d\n", descriptor);

    int rc = fork();

    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0){
       printf("File descriptor in child: %d\n", descriptor);
    }else{
       printf("File descriptor in parent: %d\n", descriptor);
    }


    return 0;
}
