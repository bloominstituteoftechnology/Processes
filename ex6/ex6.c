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
    // Your code here
    // declare structs to carry multiple var types.
    struct timespec start, end;
    // clock getttime gives us access to these system wide real time clocks, CLOCK_MONOTONIC_RAW is a monotinc time clock with access to raw harddware.
    // it is the successor to getttimeofday.
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (int i = 0; i< number_iter; i++){
      write(1, NULL, 0);
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    __uint64_t total = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    // the long long ll (el- el) modifer with the u unsigned conversion prints long long unsigned ints
    printf("%llu\n", (long long unsigned int) total/number_iter);

    return 0;
}
