// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *t_file;
    int x_file = fork();
    char filename[100], c;

    if (x_file < 0) {
        printf("The Fork Failed\n");
    }
    else {
        if (x_file == 0) {
            printf("I am the child process\n");
        }
        printf("Opening Text File\n");
        t_file = fopen("./text.txt", "r");
        if (t_file == NULL) {
            printf("Cannot open file \n");
            exit(0);
        }
    }
    c = fgetc(t_file);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(t_file);
    }
    
    printf("Closing File\n");
    fclose(t_file);
    return 0;
}
