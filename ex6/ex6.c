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
    int n = 1;
    FILE *fp;
    unint64_t diff;
    // long long unsigned int diff;
    struct timespec start, end;
    int i;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (n < number_iter)
    {
        char *childStr = "";
        fwrite(childStr, 1, strlen(childStr), fp);
        n++;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    diff = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec) / number_iter;
    printf("elapsed time = %llu nanoseconds \n", (long long unsigned int)diff);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    while (n < number_iter)
    {
        char *childStr = "";
        fwrite(childStr, 1, strlen(childStr), fp);
        n++;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    diff = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec) / number_iter;
    printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int)diff);

    return 0;
}
