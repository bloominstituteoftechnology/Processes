// Write a program that opens the text.txt  file (with the`fopen()` 
// system call) located in this directory and then calls `fork()`
// to create a new process. Can both the child and parent access 
// the file descriptor returned by `fopen()`? What happens when 
// they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// -the child and parent processes could not both access the file 
//  descriptor. the child process was able to, but after it finished,
//  the parent process was not able to access it. I suspect this is 
//  due to the file not being closed in the child process when the
//  parent process attempts to access it.
// -I don't understand what the second question is asking. 

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "r");

    int new_process = fork();
    if (new_process < 0) {
        fprintf(stderr, "fork failed\n");
    }
    else if (new_process == 0) {
        int c_c1;
        int c_c2;
        c_c1= getc(fp);
        c_c2= getc(fp);
        printf("%c, %c\n", c_c1,c_c2);
    }
    else {
        int p_c1;
        int p_c2;
        p_c1= getc(fp);
        p_c2= getc(fp);
        printf("%c, %c\n", p_c1,p_c2);
    }
    
    
    return 0;
}
