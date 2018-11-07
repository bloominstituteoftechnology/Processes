// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// reference:  https://www.programiz.com/c-programming/c-file-input-output
// use file versions:  fprintf() and fscanf()
// fwrite(address_data,size_data,numbers_data,pointer_to_file);


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fileptr;
    fileptr = fopen("text.txt", "w"); // means open for writing

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child\n");
        char *child = "test for child process\n";
        fwrite(child, sizeof(char), strlen(child), fileptr); // fwrite(address_data,size_data,numbers_data,pointer_to_file)
    } else {
        printf("parent\n");
        char *parent = "test for parent process\n";
        fwrite(parent, sizeof(char), strlen(parent), fileptr);
    }

    fclose(fileptr);

    return 0;
}
