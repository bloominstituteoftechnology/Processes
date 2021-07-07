// open system call 
//Syntax in C language 
//#include<sys/types.h>
//#includ<sys/stat.h>
//#include <fcntl.h>  
//int open (const char* Path, int flags [, int mode ]); 

#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
extern int errno; 
int main() 
{      
    // if file does not have in directory  
    // then file foo.txt is created. 
    int fd = open("foo.txt", O_RDONLY | O_CREAT);  
      
    printf("fd = %d", fd); 
      
    if (fd ==-1) 
    { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno);  
          
        // print program detail "Success or failure" 
        perror("Program");                  
    } 
    return 0; 
} 