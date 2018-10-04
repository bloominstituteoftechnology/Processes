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

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    struct timespec start, stop;

    long total = 0;
    float average = 0;
    for (int i = 0; i < number_iter; i++)
    {
        // Start time
        clock_gettime(CLOCK_MONOTONIC, &start);
        // Write to stdout
        write(1, NULL, 0);
        // End time
        clock_gettime(CLOCK_MONOTONIC, &stop);
        // Calculate time taken in nanoseconds
        total += BILLION * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec);
    }
    average = total / (float)number_iter;
    printf("The average time for each system call is %f nanoseconds\n", average);

    return 0;
}
