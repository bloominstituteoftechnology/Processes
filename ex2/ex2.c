// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Both parent and child wrote in the txt file

//referenced: https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm and https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE* fp;

    fp = fopen("text.txt", "w+");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child Process running\n");
        char* str1 = "This is the child string\n";
        fwrite(str1, sizeof(char), strlen(str1), fp);
    } else {
        printf("Parent Process running\n");
        char* str2 = "This is the parent string\n";
        fwrite(str2, sizeof(char), strlen(str2), fp);
    }

    fclose(fp);
    return 0;
}
