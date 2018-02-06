// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
// While the linked site does say that `clock_gettime()` does not work on OSX, this 
// turns out to only be the case for OSX versions < 10.12. Anything later than that 
// and `clock_gettime()` should work just fine. 

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

void current_utc_time(struct timespec *ts) {
    #ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
      clock_serv_t cclock;
      mach_timespec_t mts;
      host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
      clock_get_time(cclock, &mts);
      mach_port_deallocate(mach_task_self(), cclock);
      ts->tv_sec = mts.tv_sec;
      ts->tv_nsec = mts.tv_nsec;
    #else
      clock_gettime(CLOCK_REALTIME, ts);
    #endif
}

#define number_iter 1000000
#define BILLION 1000000000L


int main()
{
    // Your code here
    struct timespec ts;
    uint64_t total, start, end;

    for (int i = 0; i < number_iter; i++) {
        current_utc_time(&ts);
        start = ts.tv_nsec;
        write(1, NULL, 0);
        current_utc_time(&ts);
        end = ts.tv_nsec;
        total += (end - start) + (BILLION * (end - start));
    }

    float ave = total / number_iter;
    
    printf("Average time of iterations in nanoseconds: %.2f\n", ave);

    return 0;
}
