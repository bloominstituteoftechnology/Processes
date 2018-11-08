// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *file_to_read = fopen("text.txt", "r+");
    // FILE *file_to_write = fopen("newtext.txt", "w");

    if (file_to_read == NULL) {
        printf("One file wouldn't open!\n");
        return -1;
    }

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("This is child\n");
        char *child_text = "Is this working? mmmmm\n";
        fwrite (child_text, 1, strlen(child_text), file_to_read); // fprintf can also write to files
    } else {
        printf("This is parent\n");
        char *parent_text = "I don't really know! what?!\n";
        fwrite (parent_text, 1, strlen(parent_text), file_to_read);
    }
    printf("closing file\n");
    fclose(file_to_read);
    
    return 0;
}

