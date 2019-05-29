// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they write to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // This is necessary for using strlen()

int main(void)
{
    // Your code here 
    FILE* fp;
    
    fp = fopen ("text.txt", "w");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (rc == 0) {
        printf("Child: pid is %d\n", (int) getpid());
        char *child_str = "Child String\n";                        // declare a pointer to address called "Child String"
        fwrite(child_str, sizeof(char), strlen(child_str), fp);    // fwrite(pointer to the array of elements to be written, size in bytes of each element to be written, number of elements, pointer to a FILE object)
    } else if (rc > 0) {
        printf("Parent: pid is %d\n", (int) getpid());
        char *parent_str = "Parent String\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);  // fwrite(pointer to the array of elements to be written, size in bytes of each element to be written, number of elements, pointer to a FILE object)
    } 

    fclose(fp);

    return 0;
}
