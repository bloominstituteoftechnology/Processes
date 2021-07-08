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

#include <mach/clock.h> // Since OSX Yosemite doesnt have access to clock_gettime
#include <mach/mach.h>



#define number_iter 1000000
#define BILLION 1000000000L

void current_utc_time(struct timespec *ts) {
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts->tv_sec = mts.tv_sec;
  ts->tv_nsec = mts.tv_nsec;

}


int main()
{
    uint64_t diff;
    struct timespec start, end;
    int i;

    double times[number_iter + 1];

    for(int i = 0; i < number_iter; i++)
    {
        current_utc_time(&start);
        write(0, "", sizeof(char));
        current_utc_time(&end);
        times[i] = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    }
    
    double total = 0;
    
    for(int j = 0; j < number_iter; j++)
    {
        total += times[j];
    }

    total = total / number_iter;
    
    printf("Average in Nanoseconds: %lf\n", total);

    return 0;
}
