// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    int c;
    //system call to open text file to write
    fp = fopen("text.txt", "w");
    //clone parent process to a child
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //in child process
        printf("from child process, attempting to write a string to text.txt file\n");
        char child_str[] = "This is child string!\n";
        //write a string to fp (text.txt) file from child process
        fwrite(child_str, 1, sizeof(child_str), fp);
    } else {
        //in parent process
        printf("from parent process, attempting to write a string to text.txt file\n");
        char parent_str[] = "This is parent string!\n";
        //write a string to fp (text.txt) file from parent process
        fwrite(parent_str, 1, sizeof(parent_str), fp);
    }

    fclose(fp);
    //system call to open text file to read
    fp = fopen("text.txt", "r");
    while(1) {
      c = fgetc(fp);
      if( feof(fp) ) {
         break ;
      }
      printf("%c", c);
    }

    fclose(fp);

    return 0;
}
