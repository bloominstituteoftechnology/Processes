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

// This resource expands on what the timespec struct is doing: https://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/Elapsed-Time.html

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here

    uint64_t diff;

    struct timespec start, end;

    long long unsigned int elapsed_time = 0; // initialize time to 0

    for(int i = 0; i < number_iter; i++){ // find total time needed over 1 million iterations
        clock_gettime(CLOCK_MONOTONIC, &start); // write start time to start
        write(0, "", 0); // write an empty call
        clock_gettime(CLOCK_MONOTONIC, &end); // write end time to end
        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec; // use billion to refactor into nanoseconds
        elapsed_time += diff;
    }

    long long unsigned int average_time = elapsed_time/number_iter; // find the average time for each iteration

    printf("Average time = %llu nanoseconds\n", average_time);
    
    return 0;
}
