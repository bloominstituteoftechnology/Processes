// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
//execl, execv working execle and execvp not working

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    printf("forking\n");
    int rc = fork();
    char *const argsv[] = {"/bin/ls", "-l", NULL};
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Calling exec....\n");
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        //execv("/bin/ls", argsv);
        //execle("bin/ls", "ls", "arg1", "arg2", NULL, env);
        //execvp("ls", "ls", (char *)NULL);
        printf("this should not be seen\n");
    } else {
        waitpid(rc, NULL, 0);
        printf("useless parent\n");
    }

    return 0;
}

