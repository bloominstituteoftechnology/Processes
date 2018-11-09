// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main(void)
{
    // Your code here    
    int pid = fork();
    if ( pid < 0 ) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (pid == 0){
        // const char *path = "/mnt/c/Users/VLeon/Documents/Code/Lambda_School/Lambda_Projects/Processes/ex4";
        char *myargs[3];
   
        myargs[0] = strdup("/bin/ls"); 
        myargs[1] = strdup("-la"); 
        myargs[2] = NULL;
        execv(myargs[0], myargs);

        printf("this should not be seen\n");


    }else{
        wait(NULL);
        printf("Parent process");
    }

    return 0;
}


// #include<stdio.h> 
// #include<stdlib.h> 
// #include<unistd.h> cd 
// int main() 
// { 
//         //A null terminated array of character  
//         //pointers 
//         char *args[]={"./EXEC",NULL}; 
//         execv(args[0],args); 
      
//         /*All statements are ignored after execvp() call as this whole  
//         process(execDemo.c) is replaced by another process (EXEC.c) 
//         */
//         printf("Ending-----\n"); 
//         printf("args array: %s", args);
//     return 0; 
// } 

        /*
        Docs for the child component

        The execv(), execvp(), and execvpe() functions provide an array of pointers to null-terminated 
        strings that represent the argument list available to the new program. The first argument, by 
        convention, should point to the filename associated with the file being executed. The array of 
        pointers must be terminated by a NULL pointer.
        https://linux.die.net/man/3/execv 
        */