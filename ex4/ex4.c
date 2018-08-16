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
    printf("parent process here\n");
    int rc = fork();
//forking a copy
    if(rc < 0){
        fprintf(stderr, "fork failed\n");//fprint means it going into file
        exit(1);
        //error message
    }  else if (rc == 0){
        printf("Child process here\n");
//child process
//include <unistd.h> int execvp(const char *path, char *const argv[]); Like all of the exec functions, execvp replaces the calling process image with a new process image. This has the effect of running a new program with the process ID of the calling process.
      //https://linux.die.net/man/3/execv
      
      
        //exel("/bin/ls"), "ls", "-l" (char*) NULL);
        // char * args[] = {"ls", "-1", NULL};
        //execv("/bin/ls" args);
        //execlp("ls", "ls", "-1" (char *) NULL);

        char *args[] = {"ls", "-1",  NULL};
        execvp("ls", args);
    } else {
        int wc = waitpid(rc, NULL, 0);
    } 

    return 0;
}
