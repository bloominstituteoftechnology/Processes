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

/* CLOCK_REALTIME = machine's best-guess as to the current wall-clock - real-world time or time-of-day time. Kind of based on the system clock of OS.
   CLOCK_MONOTONIC = absolute elapsed wall-clock time since initiaion; essentially stopwatch.

   CLOCK_MONOTONIC does not account for time spent in suspend,
   CLOCK_BOOTTIME is the better choice if you expect some time to be spent in suspension.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main(int argc, char **argv)
{
    struct timespec start, stop;
    long accum = 0;
    long difference;
    double avg;

    for (int i = 0; i < number_iter; i++) // loop A MILLION TIMES OMG
    {
        if (clock_gettime(CLOCK_MONOTONIC, &start) == -1)
        {
            perror("clock gettime");
            exit(1);
        }

        // write NULL to stdout, pass 0 byte of data
        write(fileno(stdout), NULL, 0); // stream pointer to file descriptor 'stdout'

        if (clock_gettime(CLOCK_MONOTONIC, &stop) == -1)
        {
            perror("clock gettime");
            exit(2);
        }

        difference = BILLION * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec);
        accum += difference;
    }

    avg = accum / (float)number_iter;

    printf("Average time: %lf ns.\n", avg);
    // %f is calling for float type.
    // %lf is for double.
    return 0;
}
