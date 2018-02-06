// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? The can both access the file descriptor though they both access different parts with the 
// child continuing where the parent left off. 
// What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Open up file while checking for errors using fopen()
    FILE *file;
    char buff[255];
    int c;

    int parentProcess = getpid();
    file = fopen("./text.txt","w");

    if (file == NULL) {
        fprintf(stderr, "file not found!\n");
        return 1;
    }
    printf ("File found and able to be read!\n");
 
    // fork to create new process
    int childProcess = fork();

    if (childProcess < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (childProcess == 0) {
        // grabs the file descriptor and reading from it
        int fd = fileno(file);
        if (fd < 0) {
           fprintf(stderr, "Could not get file desciptor from child");
        }
        printf("Child access file descriptor %d\n", fd); 
        //writing to a file descriptor
        char* string = "This is a child string";
        fwrite(string, 1, strlen(string), file);
    } else {
       if (file) {
           // reads the file using a while loop until string ends 
            int fd = fileno(file);
            if (fd < 0) {
                fprintf(stderr, "Could not get file desciptor from Parent");
            }
            printf("Parent access file descriptor %d\n", fd);
            //writing to a file descriptor
            char *string = "This is a parent string";
            fwrite(string, 1, strlen(string), file);
        }   
       // fprintf(file, "Parent Data: %d\n", parentProcess);
    }
    fclose (file);
    return 0;
}
