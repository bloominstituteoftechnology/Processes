// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    uint64_t diff;
	struct timespec start, end;
	int i = 0;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (; i < number_iter; i++) write(1, "", 0); // ??what to use here - fileno(stdout) or printf
    clock_gettime(CLOCK_MONOTONIC, &end);
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    long unsigned int average = diff / number_iter;
	printf("average time = %lu nanoseconds\n", average);
    return 0;
}
