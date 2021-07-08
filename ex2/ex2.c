// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    fp = fopen("text.txt", "w");//Program tries to open text.txt
//Program checks to see if the result from fopen is null and if it is, prints a failure message to stderr and exits
// Program then prints a line of text to the now open file

    
    int rc = fork();
    //Program checks to see if the result from fopen is null and if it is, prints a failure message to stderr and exits
// Program then prints a line of text to the now open file

      if(rc < 0){
        fprint(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0){
        printf("child process here\n");
        char *child_str = "This is  child string!\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
        //If the result from that system call is less than 0, prints a failure me
        //If the value of the variable assigned to the fork system call is 0, that indicates it's the child process currently operating

    }else{
        printf("parent process here\n");
        char *parent_str = "This is parent string!\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
//Child process then prints its pid and where the pointer is for the file
// Child process then writes a message to the file
//In the parent process, the parent process prints its pid, the pid of the child process, and the pointer to the file
// The parent process then writes a message to the open file.
    }
    fclose(fp);
    return 0;
}
