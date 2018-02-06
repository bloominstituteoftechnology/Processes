// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// many file errors, no nulls though


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h> 

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * f = fopen("text.txt", "a");
    const int loop = 1000;
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec= 10000;


    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child
        for (int i = 0;i<loop;i++) {
            fprintf(f, "I am child PID %d my parent PID is %d loop # %d\n",  getpid(), getppid(), i);
            nanosleep(&sleepTime, NULL);
        }
    }
    else
    { // parent
        // int wc = waitpid(rc, NULL, 0);
        for (int i = 0;i<loop;i++) {
            fprintf(f, "I am parent PID %d loop # %d\n",  getpid(), i);
            nanosleep(&sleepTime, NULL);
        }
        fclose(f);
    }
    exit(0);    

    return 0;
}
