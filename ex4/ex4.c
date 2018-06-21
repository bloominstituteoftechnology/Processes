// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])// argc --> number of arguments, argv--> arguments array
{
    // Your code here
    printf("total args...%d \n", argc); 
    for(int i =0; i < argc; i++) {
        printf("arguments passed, %d %s \n",i, argv[i]);
    }
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Hello from the child process! pid: %d\n", (int)getpid());
        /*
         execvp(myargs[0], myargs); //
         runs the word count program, passing in the `args` array to 
         the '/bin/ls' program as arguments

         //GeekforGeeks
         int execvp (const char *file, char *const argv[]);
        file: points to the file name associated with the file being executed.
        argv:  is a null terminated array of character pointers.
        */
            
        char *args[] = {"/bin/ls", NULL}; //NULL marks the end of the array
        execvp(args[0], args);
        printf("this should not be seen");

    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Hello from the parent process! pid: %d\n", (int)getpid());
    }

    return 0;
}






        //======= OTHER EXEC CALLS ========
        // printf("Child here\n");
        // char *args[] = {"ls", "-l", NULL};
        // execvp(args[0], args);
        // execl("/bin/ls", "ls", "-l", NULL);
        // execlp("ls", "ls", "-l", NULL);