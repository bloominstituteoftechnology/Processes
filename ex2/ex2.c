// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp=fopen("./text.txt","w+");
    int c;
    int forked=fork();
    if (forked==0){
        char str[] = "This is Lambda!\n";
        fwrite(str , 1 , sizeof(str) , fp );
        fclose(fp);
        FILE *child_fp=fopen("./text.txt","r");
        do {
            c = fgetc(fp);
            if ( feof(fp) ) {
                break ;
            }
        printf("%c", c);
        } while(1);
        fclose(child_fp);
    } else{
        char str[] = "This is Sparta!\n";
        fwrite(str , 1 , sizeof(str) , fp );
        fclose(fp);
        FILE *parent_fp=fopen("./text.txt","r");
        do {
            c = fgetc(fp);
            if ( feof(fp) ) {
                break ;
            }
        printf("%c", c);
        } while(1);
        fclose(parent_fp);
    }
    return 0;
}
