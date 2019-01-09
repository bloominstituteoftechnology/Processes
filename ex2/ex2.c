// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fptr;
    if ((fptr = fopen("text.txt", "r+")) == NULL){
       printf("Error! opening file");
       exit(1);
    }

    pid_t pid = fork();
    char text_content[100];
    if (pid ==0){
        fgets(text_content, 100, fptr);
        printf("Before child write: %s\n", text_content);
        char child_input[] = "child here";
        fwrite(&child_input, 10, 1, fptr); 
        fseek(fptr, 0, SEEK_SET);
        fgets(text_content, 100, fptr);
        printf("After child write: %s\n", text_content);
    }
    else{
        fgets(text_content, 100, fptr);
        printf("Before parent write: %s\n", text_content);
        char parent_input[] = "parent here";
        fwrite(&parent_input, 11, 1, fptr); 
        fseek(fptr, 0, SEEK_SET);
        fgets(text_content, 100, fptr);
        printf("After parent write: %s\n", text_content);
    }
    fclose(fptr);
    return 0;
}
