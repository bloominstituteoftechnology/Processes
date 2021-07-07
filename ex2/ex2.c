// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
//What is the File Descripter??
//********************************************************************
//File descriptor is integer that uniquely identifies an open file of the process.

//File Descriptor table: File descriptor table is the collection of integer array indices that are 
//file descriptors in which elements are pointers to file table entries. 
//One unique file descriptors table is provided in operating system for each process.

//File Table Entry: File table entries is a structure In-memory surrogate for an open file,//
// which is created when process request to opens file and these entries maintains file position.
//**********************************************************************
//https://fresh2refresh.com/c-programming/c-file-handling/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

// int main(void)
// {
//     FILE *fp=fopen("./text.txt","w");
//     int forked=fork();
//     if (forked==0){
//         char str[] = "This is Lambda!\n";
//         fwrite(str , 1 , sizeof(str) , fp );
//     } else{
//         char str[] = "This is Cool!\n";
//         fwrite(str , 1 , sizeof(str) , fp );
//     }
//     fclose(fp);
//     return 0;
// }

int main(void)
 //declare a file pointer and use fopen() 
 //FILE *fp;
//fp=fopen (“filename”, ”‘mode”);
 //fopen() function creates a new file if the mentioned file name does not exist.
{
    FILE* fp; //fp – file pointer to the data type “FILE”
    fp = fopen("text.txt", "w"); //filename, mode such as r, w, a, r+, w+ and a+
    //w – Opens a file in write mode. It returns null if file could not be opened. If file exists, data are overwritten.
    int rc = fork(); //fork kicks in, startintg the 2nd process
   
    //catch the error
    if (rc < 0) {
        fprintf(stderr, "fork failed\n"); //function writes formatted data to a file.
        exit(1);
    } else if (rc == 0) {
        printf("coming from child\n");
        char *chi_str = "This is child string!\n";
        fwrite(chi_str, sizeof(char), strlen(chi_str), fp); //
    } else {
        printf("coming from parent\n");
        char *par_str = "This is parent string!\n";
        fwrite(par_str, sizeof(char), strlen(par_str), fp);
    }
    fclose(fp);//fclose() function closes the file that is being pointed by file pointer fp. 
    return 0;
}
