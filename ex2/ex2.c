// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    char str[60];
    fp = fopen("text.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return(-1);
    }
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        if( fgets (str, 4, fp)!=NULL ) {
            printf("child string %s", str);
        }
        if( fgets (str, 4, fp)!=NULL ) {
            printf("child string %s", str);
        }
        printf("child string");
    } else {
        if( fgets (str, 4, fp)!=NULL ) {
            printf("parent string %s", str);
        }
        if( fgets (str, 4, fp)!=NULL ) {
            printf("parent string %s", str);
        }
    }
    
    return 0;
}
