// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define CHUNK 1024 /* read 1024 bytes at a time */

int main(int argc, char *argv[])
{
    FILE *fp_write = fopen("text.txt", "w");
    int child = fork();

    if (child < 0)
    {
        perror("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        fprint("%d", child);
        fprintf(fp_write, "%s", "I am the child writing!\n");
    }
    else
    {
        fprint("%d", child);
        fprintf(fp_write, "%s", "I am the parent writing!\n");
    }
    fclose(fp_write);
    // char buffer[2];

    // FILE *fp_read = fopen("text.txt", "r");

    // while (fgets(buffer,2 , fp_read)) 
    // {
    //     printf("%s", buffer);
    // }

    // fclose(fp_read);
    
char buf[CHUNK];
FILE *file;
size_t nread;

file = fopen("text.txt", "r");
if (file) {
    while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
        fwrite(buf, 1, nread, stdout);
    if (ferror(file)) {
        /* deal with error */
    }
    fclose(file);
}

    return 0;
}