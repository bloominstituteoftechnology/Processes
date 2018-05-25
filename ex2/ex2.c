// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>  // to use FILE, fopen(), fprintf()
#include <unistd.h> //
#include <stdlib.h> //

// to use open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    printf("I am (parent): %d\n", (int)getpid());

    // declare file pointer of type FILE
    // the file pointer is needed for communication between the file and program
    FILE *fptr;
    // file pointer
    fptr = fopen("./text.txt", "a");
    // file descriptor
    int fd = open("./text.txt", O_WRONLY);
    printf("fd value: %d\n", fd);

    int isFptrClosed = 1;
    int isFdClosed = 1;

    // fopen returns NULL if unsuccessful
    if (fptr == NULL)
    {
        printf("FOPEN failed\n");
        exit(1);
    }

    printf("FILE address: %p\n", fptr); // %p pointer address

    pid_t pid = fork();
    printf("Fork returned: %d\n\n", (int)pid);

    if (pid < 0)
    {
        // custom error printing
        fprintf(stderr, "FORK failed\n");

        // terminates with error
        exit(1);
    }
    else if (pid == 0)
    {

        printf("Child with pid %d\n", (int)getpid());
        printf("FILE address: %p\n", fptr); // %p pointer address
        printf("fd value: %d\n", fd);
        write(fd, "Child writing using File Descriptor\n", 36);
        fprintf(fptr, "Child writing using File Pointer\n");
    }
    else
    {

        printf("Parent with pid %d\n", (int)getpid());
        printf("FILE address: %p\n", fptr);
        printf("fd value: %d\n", fd);
        write(fd, "Parent writing using File Descriptor\n", 72);
        fprintf(fptr, "Parent writing using File Pointer\n");
    }

    // closes the file pointer/file descriptor after reading/writing
    // fclose()/close() returns 0 if successful
    isFptrClosed = fclose(fptr);
    isFdClosed = close(fd);

    if (isFptrClosed != 0)
    {
        printf("FCLOSE failed\n");
        exit(1);
    }
    printf("FCLOSE successful\n");

    if (isFdClosed != 0)
    {
        printf("CLOSE failed\n");
        exit(1);
    }
    printf("CLOSE successful\n");

    return 0;
}

// output

// I am (parent): 2780
// fd value: 4
// FILE address: 0x7fff96fb0030
// Fork returned: 2781

// Parent with pid 2780
// FILE address: 0x7fff96fb0030
// fd value: 4
// FCLOSE failed
// Fork returned: 0

// Child with pid 2781
// FILE address: 0x7fff96fb0030
// fd value: 4
// isFptrClosed: 0
// FCLOSE successful

// !! When access to fclose()/close() is unrestricted to parent and child, fclose()/close() is successful for both
// !! When access to fclose()/close() is restricted to parent only, only the parent is successful; likewise with the child
