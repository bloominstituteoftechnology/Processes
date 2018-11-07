// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
/*
It seems that both the child and the parent has access. 
They also write to the file in the order they are reached. 
Example if parent is written first  it writes  then  the child will add underneath wher the parent left off. 
https://repl.it/@codejoncode/Lambda-Exercise-2
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // FILE *fopen(const char *filename, const char *mode);
    FILE *fp; 
    fp = fopen("text.txt", "r+");
    int rc = fork(); 


    if(rc == 0){
      fprintf(fp, "%s\n", "Inside of child");
      printf("Inside of the child\n");
    } else{
      fprintf(fp, "%s\n", "Inside of parent");
      printf("Inside the parent\n");
    }
    fclose(fp);
    return 0;
}

/*
The C library function FILE *fopen(const char *filename, const char *mode) opens the filename pointed to, by filename using the given mode.

Following is the declaration for fopen() function.

FILE *fopen(const char *filename, const char *mode)
          Mode & Description 
"r"  :  Opens a file for reading. The file must exist. 
"w" : Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file. 
"a" :  Appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist. 
"r+" :  Opens a file to update both reading and writing. The file must exist. 
"w+": Creates an empty file for both reading and writing. 
"a+" : Opens a file for reading and appending. 


*/