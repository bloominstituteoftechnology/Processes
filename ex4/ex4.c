// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here    
    printf("Parent process\n");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process\n");
        execl("/bin/ls", "ls", "-1", (char *) NULL);
    } else {
        wait(NULL);
    }

    return 0;
}

//instructor solve

// int main(int argc, char* argv[])
// {
//     int rc = fork();

//     if (rc < 0) {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {
//         printf("child here\n");
//         char *args[] = {"ls", "-l", NULL};
//         execvp("ls", args); 
//     } else {
//         int wc = wait(NULL);
//         printf("parent here\n");
//     }
    
//     return 0;
// }

//other options to go in place of execvp above (remove lines 40 & 41 & replace with either below)

// execl("/bin/ls", "ls", "-l", NULL);

// execlp("ls", "ls", "-l", NULL);
