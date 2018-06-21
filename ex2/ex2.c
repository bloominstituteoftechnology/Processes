// Write a program that opens the text.txt file 
// (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. 
// Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are
//  written to the file concurrently?

/*
Both the child and parent can access the file descriptor. 
They can write to the file concurrently. 
But it is up to the operating system to decide whether
 the parent or the child runs first after the fork call, 
 and it may change from run to run.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    FILE *fp;
    fp = fopen("text.txt", "w");

    int ret = fork();
        if (ret < 0) {
            fprintf(stderr, "No Good :(");
            exit(1);
        }
        else if( ret == 0) {
            printf("Child process HERE\n");
            char childStr[] = "Child writes this str\n";
            fwrite(childStr, 1, sizeof(childStr), fp);
        }

        else {
            printf("Parent process HERE\n");
            char parentStr[] = "Parent writes this str\n";
            fwrite(parentStr, 1, sizeof(parentStr), fp);
        }
        
        fclose(fp);

    return 0;
}
