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
#define BILLION 1000000000L  // do not try an malloc this much space!

int main()
{
    // Your code here
    long int *times_nanosec = malloc(sizeof(long int) * number_iter);
    struct timespec start, end;

    for (long int i = 0; i < number_iter; i++)
    {
        clock_gettime(CLOCK_REALTIME, &start);

        printf("\nOutput\n: %ld", i);
        
        clock_gettime(CLOCK_REALTIME, &end);

        *(times_nanosec + i ) = end.tv_nsec;
    }

    long int times_sum = 0;

    for (long int i = 0; i < number_iter; i++)
    {
        times_sum = times_sum + *(times_nanosec + i );
    }

    printf("\n\n=====\nAverage Time in Nanoseconds: %ld\n=====\n\n", times_sum / number_iter);
    
    free(times_nanosec);
    
    return 0;
}
