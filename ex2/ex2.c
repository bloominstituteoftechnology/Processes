// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Answer: The child and parent can indeed print one after another.  If you try to run the entire program
// again,

// `gcc -Wall -Wextra -o ex2 ex2.c`
//  `./ex2`

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // Need this to create child_str

// int argc, char *argv[]
int main()
{
    FILE *fp;                     // create a file pointer
    fp = fopen("text.txt", "w+"); // assign pointer to file and grant access powers. https://www.geeksforgeeks.org/data-type-file-c/
    int rc = fork();
    printf("ex2 executing...\n");

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Hi, I am child (pid: %d)\n", (int)getpid());
        char *child_str = "This is just a string from child!\n";
        fwrite(child_str, 1, strlen(child_str), fp);
        // fprintf(fp, "Child printed this!\n");
    }
    else
    {
        printf("Hi, I am parent of %d (pid: %d)...\n", rc, (int)getpid());
        char *parent_str = "This is just a string from parent!\n";
        fwrite(parent_str, 1, strlen(parent_str), fp);
        // fprintf(fp, "Parent printed this!\n");
    }
    fclose(fp);
    return 0;
}
