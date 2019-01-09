// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
//the child and parent can both access the file descriptor returned by fopen()
//when they are written to the file concurrently the text appears non-deterministically as either the text from the parent or the child 
//may appear first.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp=fopen("./text.txt","w");
    int forked=fork();
    if (forked==0){
        char str[] = "This is Lambda!\n";
        fwrite(str , 1 , sizeof(str) , fp );
    } else{
        char str[] = "This is Sparta!\n";
        fwrite(str , 1 , sizeof(str) , fp );
    }
    fclose(fp);
    return 0;
}
