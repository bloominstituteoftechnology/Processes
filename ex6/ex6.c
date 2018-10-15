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
#include <stdint.h> // for unit64 definition
// #include <stdlib.h> // for exit() definition
#include <unistd.h> // system calls
#include <time.h>   // for clock_gettime

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    struct timespec start, end;
    long sum = 0;
    long difference;
    double avg;

    for (int i = 0; i < number_iter; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &start); //CLOCK_MONOTONIC	Represents monotonic time since some unspecified starting point. This clock cannot be set.
        write(fileno(stdout), NULL, 0);
        //     printf("");
        getpid();
        clock_gettime(CLOCK_MONOTONIC, &end); // mark the end time
        difference = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        sum += difference;
    }
    avg = sum / (float)number_iter; // precise time
    printf("Average time per write is %f ns.\n", avg);
    return 0;
}
