// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    /*
    from www.tutorialspoint.com/cprogramming/c_file_io.htm
    You can use the fopen( ) function to create a new file or to open an existing file. This call will initialize an object of the type FILE, which contains all the information necessary to control the stream. The prototype of this function call is as follows − `FILE *fopen( const char * filename, const char * mode );`
    */
    // w+ = Opens a text file for both reading and writing. It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist.
    
    FILE *fp;

    fp = fopen("text.txt", "w+");
    printf("Initial Process (pid: %d)\n", (int) getpid());

    // create a new process by calling fork()
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if(rc == 0)
    {
        printf("Child process (pid: %d)\n", (int) getpid());
        fputs("This is written by Child.\n", fp);
    }
    else
    {
        printf("Parent process (pid: %d)\n", (int) getpid()); 
        fputs("This is written by parent.\n", fp);
    }

    fclose(fp);

    return 0;
}
