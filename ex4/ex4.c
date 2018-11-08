// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

//execl(), execle(), execlp(), execlpe(), execv(), execve(), execvp(), execvpe()
    //The different versions have take different forms of parameters. If it is an L, you need to pass individual parameters, whereas V takes an array of char pointers. E allow you to introduce
    //    char pointers prior into the new process environment but prior to the launch of the executable program. P indicates whether the filename path has to be absolute or relative. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int forked = fork();
    
    if (forked < 0) {    
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (forked == 0) {    
        char *args[]={"/bin/ls", NULL}; 
        execvp(args[0], args); 
    } else {
        int wc = waitpid(forked, NULL, 0);
        printf("Parent %d\n");
    }

    return 0;
}
