// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main(int argc, char* argv[])
// {
//     // Your code here 
    
//     return 0;
// }
// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * fp;
    int c;
    fp = fopen("text.txt", "r");
    if (fp) {
        while ((c = getc(fp)) != EOF)
            putchar(c);
            printf("\n");
    }

    fclose(fp);

    return 0; 
    }