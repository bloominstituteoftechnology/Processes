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
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    struct timespec start, end;
    int diff;
    int nano;
    int sum;
    int avg;

    
    for(int i =0;i <number_iter;i++)
    {
        clock_gettime(CLOCK_MONOTONIC,&start);
           // write(fileno(stdout,"",0));
           
           // is a lot faster
           printf("");
        clock_gettime(CLOCK_MONOTONIC,&end);
        diff = end.tv_sec - start.tv_sec;
        nano = end.tv_nsec - start.tv_nsec;
       sum += BILLION * diff + nano;
     
    }
avg = sum / number_iter;
    printf("your average system call time in nanosecs: %d \n",avg);
    
    return 0;
}
