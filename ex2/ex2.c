// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *ptr_file;
    char buf[1000];
    int rc = fork();

    ptr_file = fopen("./text.txt", "r+");
    if(!ptr_file) {
        return 1;
    }

    while (fgets(buf,1000, ptr_file) != NULL)
        if(rc < 0) {
            fprintf(stderr, "unable to fork\n");
            exit(1);
        } else if (rc == 0) { // this is the child fork
            fputs("This has been added from the child process\n", ptr_file);   
            printf("This is from the child: %s\n", buf);
            
        } else { // this is the parent
            fputs("This has been added from the parent process\n", ptr_file);
            printf("This is from the Parent: %s\n", buf);    
        }

    fclose(ptr_file);

    return 0;
}
