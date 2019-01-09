//The exec family of functions replaces the current running process with a new process. 
//It can be used to run a C program by using another C program.

//execvp : Using this command, the created child process does not have to run the same program as the parent process does. 
//The exec type system calls allow a process to run any program files, which include a binary executable or a shell script . Syntax:
//int execvp (const char *file, char *const argv[]);
//File: points to the file name associated with the file being executed.
//argv:  is a null terminated array of character pointers.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    //A null terminated array of character  
        //pointers 
        char *args[]={"./EXEC",NULL}; 
        execvp(args[0],args); 
      
        /*All statements are ignored after execvp() call as this whole  
        process(execfunts.c) is replaced by another process (EXEC.c) 
        */
        printf("Ending-----"); 
      
    
    return 0;
}