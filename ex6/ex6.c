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
#include <time.h> // clock_gettime comes from here

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{ 
    int monotime = 0;
    int cpu_time = 0;
    
    for (int i=0; i<number_iter; i++) { // It'll do this for one million iterations

        uint64_t diff; //diff = time elapsed
	    struct timespec start, end;
	    int i;

	    /* measure monotonic time */
	    clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

        write(STDOUT_FILENO,"", 0);
    

	    clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */


	    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	    printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
        if(monotime == 0) {
            monotime = diff;
        } else {
        monotime = (monotime + diff)/2;
        }


	    /* now re-do this and measure CPU time */
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */

        write(STDOUT_FILENO,"", 0);
        //for your computer to make a system call an empty write to stdout

	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

	    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	    printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);
        //moving average calculation 
         if (cpu_time == 0) {
            cpu_time = diff;
        } else {
        cpu_time = (cpu_time + diff)/2;
        }//moving average calculation 

	    exit(0);
    }

    //then find the average of all of those iterations in nanoseconds.
    printf("monotime =%d\n", monotime);
    printf("cpu_time =%d\n", cpu_time);
    return 0;
}
