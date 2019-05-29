// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


// Questions:
// What are the arguments supposed to be? how do you know?
// In readme example, does wc get declared in line 123 before it's needed in line line 117?

int main(int argc, char *argv[]) 
{
    // Your code here    
    printf("Parent process\n");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process\n");

        // execl("/bin/ls", "ls", "-l" (char *) NULL);
        
        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);

        //execlp("ls", "ls", "-l", (char *) NULL);

        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
    } else {
        int wc = waitpid(rc, NULL, 0);
    }
    return 0;
}
