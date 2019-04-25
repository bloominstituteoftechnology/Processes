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
#include <time.h> // for clock_gettime

#define number_iter 1000000 // 1 million iterations
#define BILLION 1000000000L

// AVERAGE OF 1 MILLION ITERATIONS - CLOCK_MONOTONIC (~99k-102k nanosecs)
int main()
{
    // Your code here
    uint64_t diff;                       // variable for difference between start and end times
    long long unsigned int total_times;  // variable for total of 1 million iterations
    long long unsigned int average_time; // variable to hold average of 1 million iterations
    struct timespec start, end;          // declare 2 structs to hold start and end times (includes secs and nanosecs in each struct)

    // CLOCK_MONOTONIC - Unspecified starting point for measuring elapsed time
    for (int i = 0; i < number_iter; i++)
    {                                           // loops through 1 million times
        clock_gettime(CLOCK_MONOTONIC, &start); // start the elapse timer
        fileno(stdout);                         // empty write to stdout
        clock_gettime(CLOCK_MONOTONIC, &end);   // end the elapse timer

        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec; // total up differences of start and end
        total_times = total_times + diff;                                           // add the total time to total_times buffer variable
    }

    average_time = total_times / number_iter; // calculates average time
    printf("CLOCK_MONOTONIC Average Time = %llu nanoseconds\n", average_time);
    return 0;
}
