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
   printf("Parent process here\n");
    int rc = fork(); 

    
    if (rc == 0){
      printf("Child process here\n");

      char *args[] = {"ls", "-l", NULL};
      execv("/bin/ls", args); 
    } else {
      wait(NULL);
    }    

    return 0;
}

/*
Every application(program) comes into execution through means of process, process is a running instance of a program. Processes are created through different system calls, most popular are fork() and exec() 

The exec() family of functions replaces the current process image with a new process image. It loads the program into the current process space and runs it from the entry point. 

Difference of fork and exec  

Fork starts a new process which is a copy of the one that calls it, while exec replaces the current process image with another (different) one. 

Both parent and child processes are executed simultaneously in case of fork() while Control never returns to the original program unless there is an exec() error.  


int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ..., 
                               char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[], 
                              char *const envp[]);


The new image shall be constructed from a regular, executable file called the new process image file. There shall be no return from a successful exec, because the calling process image is overliad by the new process image. 

Current process stops and another process runs instead  with Exec() 

Header file: #include<unistd.h> 
int execv(char const *path, char const *argv[])
path: the path name of the file to execute as the new process image 
loads new program into process space and runs it from the entry point. 

argv: an array of argument strings passed to the new program and it must be terminated by a null pointer 


Return value: 
does not return on success  
becasue it will directly execute a new process on successful execution. 

*/
