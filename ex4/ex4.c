// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // char *args[]={"/bin/ls",NULL}; 
        // execvp(args[0],args);

        // char *args[]={"/bin/ls",NULL};
        // execv(args[0],args);

        //execl("/bin/ls", "/bin/ls", NULL);

        execle("./exec", "./exec", NULL);

        printf("everything after exec() is ignored as the current process is replaced with another process\n");
    } else {
        int wc = waitpid(rc, NULL, 0);
    }

    return 0;
}
