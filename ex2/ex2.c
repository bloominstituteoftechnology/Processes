// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
int c;
FILE *file;// pointer of FILE type
file = fopen("text.txt", "r"); // open file <name> in CWD and read
    if (file) {
        while ((c = getc(file)) != EOF){ // as long as there not EOF
            putchar(c); // keep printing chars
        }
        fclose(file);// close the file stream
    }
}
