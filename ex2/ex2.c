// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *poo;
    poo = fopen("text.txt", "r+");
    int rc = fork();
    if(rc < 0) {
     fprintf(stderr, "fork failed\n");
        exit(1);
 }
  else if(rc == 0){
     printf("Child thing (pid: %d) \n", (int) getpid());
     fprintf(poo, "This is my child\n");
 } 
 else { 
     printf("Parent thing (pid: %d) \n", (int) getpid());
     fprintf(poo, "This is my parent\n");
 }
    //"r+" means for reading and writing https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm

    return 0;
}
