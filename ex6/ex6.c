/*
Author Jonathan Jamel Holloway 
Purpose: 
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

Date: 11-8-18

completed link https://repl.it/@codejoncode/Lambda-Exercise-6

*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    struct timespec start, end; 
    uint64_t diff; 
    // to print this out use %llu   then (long long unsigned int) dif as the variable part of the printf statement
    int totalCount = number_iter;
    int const divideBy = number_iter; 
    int totalTime = 0; // using this to add up the total time. 
    //total time will be the difference between the start and the end. 
    float averageTime; 

    while(totalCount > 0){
      clock_gettime(CLOCK_MONOTONIC, &start); 
      printf("");//printf is using
      clock_gettime(CLOCK_MONOTONIC, &end);
      diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec; 
      totalTime = totalTime + diff; 
      totalCount--;

    }
    
    printf("%d\n", totalTime); 
    // averageTime = totalTime / number_iter; 
    averageTime = totalTime / divideBy; 
    printf("%.2f\n", averageTime); 
    
    return 0;
}

/*The clock_gettime call is a successor to the gettimeofday system call with a few key changes:  higher precision and the ability to request specfic clocks. 

It fills in a structure containing two fields: a seconds and a nanosecond count of the time since the Epoch (00:00 1 January, 1970 UTC).   

This is similar to the struct timeval that gettimeofday used except that the microsecond field is now replaced with a nanosecond field. 

struct timespec {
  time_t tv_sec   //seconds 
  long   tv_nsec  //nanoseconds 
};

The clock_gettime system call has the following usage:

#include <time.h>   //required header  

int clock_gettime(clockid_t clk_id, struct timespec *tp);

The second parameter is the time structure that will be filled in by the system call to contain the value of the clock. The first parameter, clock ID, allows you to specify the clock you are interested in using 

CLOCK_REALTIME	System-wide real-time clock. This clock is supported by all implementations and returns the number of seconds and nanoseconds since the Epoch. This clock can be set via clock_settime but doing so requires appropriate privileges. When the system time is changed, timers that measure relative intervals are not affected but timers for absolute point in times are.
CLOCK_REALTIME_COARSE (Linux-specific)	Faster than CLOCK_REALTIME but not as accurate.
CLOCK_MONOTONIC	Represents monotonic time since some unspecified starting point. This clock cannot be set.
CLOCK_MONOTONIC_RAW (Linux-specific)	Similar to CLOCK_MONOTONIC, but provides access to a raw hardware-based time that is not subject to NTP adjustments.
CLOCK_MONOTONIC_COARSE (Linux-specific)	Like CLOCK_MONOTONIC but faster and not as accurate.
CLOCK_PROCESS_CPUTIME_ID	High-resolution per-process timer from the CPU.
CLOCK_THREAD_CPUTIME_ID	Thread-specific CPU-time clock.

For getting the system's idea of the time of day (in seconds since the Epoch), one should use clock_gettime(CLOCK_REALTIME, &tp).

For measuring elapsed time, CLOCK_MONOTONIC is recommended. This clock will not necessarily reflect the time of day but, unlike CLOCK_REALTIME, it is guaranteed to always be linearly increasing (although not necessarily between reboots). CLOCK_MONOTONIC is affected by adjustments caused by the Network Time Protocol (NTP) daemon. However, NTP adjustments will not cause this clock to jump; it's rate might be adjusted to compensate for clock drift. CLOCK_REALTIME, on the other hand, may leap forward or even backward after a time adjustment.


*/