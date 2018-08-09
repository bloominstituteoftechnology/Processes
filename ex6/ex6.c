/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the
`clock_gettime` procedure to time how long a single system call takes. It'll
do this for one million iterations, and then find the average of all of those
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this
turns out to only be the case for OSX versions < 10.12. Anything later than that
and `clock_gettime()` should work just fine.
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

#define number_iter 1000000
#define BILLION 1000000000L
#define MSGSIZE sizeof(double)

int main(void)
{
    long inbuf[MSGSIZE];
    int p[2];
    long result;

    if (pipe(p) < 0) { //initialize pipe
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    int forked = fork();
    int i = 1;

    while (forked > 0 && i < 1000) {
        usleep(5);
        forked = fork();
        i++;
    }



    if (forked < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (forked == 0) { //this is the child process
        struct timespec start, stop;
        clock_gettime(CLOCK_MONOTONIC, &start);
        printf("");
        clock_gettime(CLOCK_MONOTONIC, &stop);
        result = ( stop.tv_nsec - start.tv_nsec );
        write(p[1], &result, MSGSIZE);
    }
    else { //this is the parent process
        waitpid(forked, NULL, 0);
        long sum = 0;
        for (int i = 0; i < 1000; i++) {
            read(p[0], inbuf, MSGSIZE);
            sum += *inbuf;
        }
        long average_time = sum / 1000;
        printf("%ld\n", average_time);
    }
    return 0;
}
