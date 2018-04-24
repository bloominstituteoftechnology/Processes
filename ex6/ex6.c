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

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
	int diff;
	int total = 0;
    int nano;
    // structuring timespec start and end object that will 
    // have access to 'tv_sec' (whole second) and 'tv_nsec' (microsecond)
 
    struct timespec start, end;

    // iteration
    for (int i = 0; i < number_iter; i++) {
    	//get time before system call
        clock_gettime(CLOCK_MONOTONIC, &start);
        //system call an empty write to stdout
        write(STDOUT_FILENO, NULL, sizeof(NULL));
        // get time after system call
        clock_gettime(CLOCK_MONOTONIC, &end);
        // get the average in nano seconds by multiplying each system call time by a billion
        // and dividing it by number of iteration
        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        total += diff;
    }
    // get average system call time in nano second
    nano = total / number_iter;

    printf("Average system call time in nanoseconds is: %d\n", nano);
    
    return 0;
}
