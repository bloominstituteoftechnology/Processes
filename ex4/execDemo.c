#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
        //A null terminated array of character  
        //pointers 
        char *args[]={"./exec",NULL}; 
        execv(args[0],args); 
      
        /*All statements are ignored after execvp() call as this whole  
        process(execDemo.c) is replaced by another process (EXEC.c) 
        */
        printf("Ending-----"); //replace the execDemo.c with EXEC.c by calling execv() function
      
    return 0; 
} 