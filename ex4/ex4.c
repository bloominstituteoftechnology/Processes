// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

/*
A: Seems like varying levels of complexity of the same sorts of operations
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    printf("Hello from Main (pid: %d)\n", (int) getpid());
    printf("Main says: x = %d \n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x -= 50;
        printf("Hello from Child (pid: %d)\n", (int) getpid());
        printf("Child says: x = %d \n", x);
    } else {
        // DISRUPT!!!
        int ret;
        ret = execl("/bin/ls", "ls", "-1", (char *)0);
        
        // ret = execlp ("ls", "ls", "-l", (char *)0);

        // char *cmd[] = { "ls", "-l", (char *)0 };
        // ret = execv ("/bin/ls", cmd);

        // char *cmd[] = { "ls", "-l", (char *)0 };
        // char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
        // ret = execve ("/bin/ls", cmd, env);

        x += 25;
        printf("Hello from Parent (pid: %d)\n", (int) getpid());
        printf("Parent Process says: x = %d \n", x);
    }
    printf("Final check says: x = %d \n", x);
    return 0;
}
