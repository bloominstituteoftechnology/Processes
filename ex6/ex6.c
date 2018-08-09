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

int main(void)
{
    struct timespec start, end;
    long accum = 0;
    long difference;
    double avg;

    for (int i = 0; i < number_iter; i++) {
        // created 2 structs, 1 for start times, one for endtimes
        // CLOCK_MONOTONIC lets us measure the time between 2 points we chose
        clock_gettime(CLOCK_MONOTONIC, &start);

        write(fileno(stdout), NULL, 0);
        // Execution of program without overwriting the parent process
        // as we'd do with execl()

        clock_gettime(CLOCK_MONOTONIC, &end);
        // writing the end time
        accum += BILLION * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
        // adding to the total time needed      
    }

    avg = accum / (float) number_iter;
    // calculating the average :)
    printf("Average time to execute our system call:  %f ns.\n", avg);

    return 0;
}
