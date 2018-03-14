// Write a program that opens the text.txt  file (with the `fopen()` system call) 
//located in this directory 
// and then calls `fork()` to create a new process. Can both the child and 
//parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// see https://www.programiz.com/c-programming/c-file-input-output

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
      // Your code here
      // get the file descriptor
     int num;
     FILE *fptr;
     fptr = fopen("text.txt","a+");

     if(fptr == NULL)
     {
        printf("Error!");   
        exit(1);             
     }

     // start forking and writing to files
     int forked = fork();
     if(forked == 0){  // child process
         printf("hello\n");
         printf("Enter num: ");
         scanf("%d",&num);
         fprintf(fptr,"%d",num); // 2
         fclose(fptr);
     } else{
        waitpid(forked, NULL, 0); // wait until the child process finishes
        printf("Enter num: ");
        scanf("%d",&num);
        fprintf(fptr,"%d",num);  //3
        fclose(fptr); 
        printf("goodbye\n");
     }
     return 0;
}

// contents of the file after running program 23 . conclusion, because i opened the file 
// in append mode the descriptor is like a key to the file you can append to the file
// in different processes . 