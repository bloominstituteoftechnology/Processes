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
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L
#define KAJILLIONBILLIONZILLION 1000000000000000000000000000000000000000000000000000L

int main()
{
    unsigned long long clock_ticks = 0;
    clock_t a_clock;
    for (size_t i = 0; i < number_iter; i++) {
        a_clock = clock();
        printf("");
        clock_ticks += (unsigned long long)(clock() - a_clock);
    }
    printf("Average of %lu runs is %llu nanoseconds\n", 
        number_iter, (clock_ticks * BILLION / CLOCKS_PER_SEC) / number_iter);
    return EXIT_SUCCESS;
}
