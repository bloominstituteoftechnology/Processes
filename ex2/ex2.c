// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *file = fopen("text.txt", "w");

    int forky = fork();

    if (forky < 0)
    {
        printf("SOMETHING TerRIBLE HAS HAPPENed, or something");
        exit(1);
    }
    else if (forky == 0)
    {
        char str[] = "beans and rice, please";
        fwrite(str, 1, sizeof(str)-1, file);
        fclose(file);
    }
    else
    {
        char str[] = "If my child asks for rice or beans, do not give those to them\n";
        fwrite(str, 1, sizeof(str)-1, file);
        // printf("this is str: %s\nand size of srt: %lu\n", str, sizeof(str));
        fclose(file);
    }
    return 0;
}


//looks like parent writes, then child writes
