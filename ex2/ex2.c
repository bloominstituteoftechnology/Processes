// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they BOTH WRITE to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // open the file contained in this folder
    FILE *fp;
    fp = fopen("text.txt", "r+");
    char c;

    int rc = fork();
    if (rc<0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("child here, the file pointer is: %p\n", fp);
        // printf("the contents of the file are:\n");
        // c = fgetc(fp);
        // while (c != EOF) {
        //     printf("%c", c);
        //     c = fgetc(fp);
        // }
        char *child_str = "Child writes to the file! \n";
        fwrite(child_str, 1, strlen(child_str), fp);
    }
    else {
        // wait until child resolves
        int wc = waitpid(rc, NULL, 0);
        printf("parent here, the file pointer is: %p\n", fp);

        char *parent_str = "Parent also writes to the file! \n";
        fwrite(parent_str, 1, strlen(parent_str), fp);

        // resets the fp to the top of the file so everything can be read by the fgetc
        rewind(fp);

        printf("the contents of the file are:\n");
        c = fgetc(fp);
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(fp);
        }
    }
    fclose(fp);
    return 0;
}

// both the child and the parent processes have access to the pointer, however, as would be expected of a text file, only one process could read from the file at a time. However, both were able to write to the file. curious how this would work with a shared document, if any were even available to be read at this level...
// file close must be executed by the outer function, otherwise it causes read errors.