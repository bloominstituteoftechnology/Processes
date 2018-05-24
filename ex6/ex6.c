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

#include <stdio.h>  // for printf
#include <unistd.h> //unsigned int
#include <stdlib.h> // exit() definition
#include <time.h>   // for clock_gettime

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    uint64_t diff;
    uint64_t totalDiffTime = 0;
    uint64_t averageTime;
    struct timespec start, end;
    int i;

    // do it a million times
    for(i = 0; i < number_iter; i++){
        clock_gettime(CLOCK_MONOTONIC, &start); // marks start time
        write(1, "hello\n", 8);
        clock_gettime(CLOCK_MONOTONIC, &end); // marks the end time
        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        totalDiffTime += diff;
    }
    printf("average elapsed time = %llu nanoseconds\n", (long long unsigned int) totalDiffTime/ i);

    return 0;
}
