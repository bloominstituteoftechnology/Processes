// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the
// `clock_gettime` procedure to time how long a single system call takes. It'll
// do this for one million iterations, and then find the average of all of those
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define number_iter 1000000
#define BILLION 1000000000L

int diff;
struct timespec start, end;
int i;

int main()
{
    int j = 0;
    long tot, avg;
    const char msg[] = "";
    while (j < number_iter)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        write(STDOUT_FILENO, msg, sizeof(msg) - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);

        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_sec - start.tv_sec;
        tot += diff;
        j++;
    }

    avg = tot / number_iter;
    printf("%li\n", avg);

    return 0;
}
