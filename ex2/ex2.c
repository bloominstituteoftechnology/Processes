// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * fp;
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0 ){
        printf("Didn't work");

       
    } else if (rc == 0){//Child
        fputs("This is the child", fp);

     
    } else {//Parent
        fputs("This is the parent", fp);
    }
    
    fclose(fp);
    
    return 0;
}
