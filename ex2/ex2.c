// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 

    FILE *file;

    printf("text.txt file is being opened in read/write mode with fopen.");

    file = fopen("text.txt", "r+");
    if (file == NULL){
        printf("There is no such a file text.txt");
        return 1;
    }

    int f = fork();

    if (f < 0) {
        fprintf(stderr, "Forking failed.\n");
        exit (1);
    } else if (f == 0) {

        printf("\nChild forking process.\n");
        char *fileStringOne = "I believe i can touch the sky:O\n";
        fwrite (fileStringOne, 1, strlen(fileStringOne), file);

    } else {

        printf("\n Parent process\n");
        char *fileStringTwo = "I believe i can fly  :D \n";
        fwrite (fileStringTwo, 1, strlen(fileStringTwo), file);
        
    }

    printf("text.txt file is closing\n");
    fclose(file);    
    return 0;
}
