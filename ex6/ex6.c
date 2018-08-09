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
    uint64_t diff;
    struct timespec start, end;
    float average;
    long long unsigned times = 0;
    long long unsigned temp[number_iter];
    int p;


// I wanted to see if there was a difference in the time it takes to add the time from every iteration to the total time
// versus just adding the time on every iteration to an index on an array
// Turns out, there's not a difference once I cast both methods to the same data type.  Get ~ 85 - 90 nanoseconds

    for (int i = 0; i < number_iter; i++)
    {
        clock_gettime(CLOCK_REALTIME, &start);
        printf("");
        clock_gettime(CLOCK_REALTIME, &end);
        
        temp[i] = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
        times = times + (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    }
    long long unsigned length = sizeof(temp)/sizeof(long long);
    printf("The length of a long long is %llu\n", length);

    long long unsigned aaaah = 0;
    for (int j = 0; j < length; j++)
    {
        aaaah += *(&temp[j]);
    }
    average = (float)times/number_iter;
    printf("The average time was %f nanoseconds\n", average);
    printf("The average time was %f nanoseconds\n", (float)aaaah/number_iter);

// Just wanted to test how much difference it made to time the number of iterations and then average
// Average ended up being ~60 - 65 using this method
 // I imagine that's because the way that this method works, it starts from a sleep and then times the process
 // So since it's only running the start once, it's only starting from sleep on one occasion

        // clock_gettime(CLOCK_MONOTONIC, &start);
        //     for (int i = 0; i < number_iter; i++)
        //     {
        //         printf("");
        //     }        
        // clock_gettime(CLOCK_MONOTONIC, &end);

        // diff = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);

        // average = diff/number_iter;

        // printf("The average run time is %f nanoseconds\n", average);

// Hilariously, this same set up but changing the function from an empty print to a getpid() call,
// Time goes from ~90 to ~30

    // for (int i = 0; i < number_iter; i++)
    // {
    //     clock_gettime(CLOCK_REALTIME, &start);
    //     p = getpid();
    //     printf("%d\n", p);
    //     clock_gettime(CLOCK_REALTIME, &end);
        
    //     temp[i] = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    //     times = times + (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    // }        
    // printf("%d\n", p);
    // long long unsigned length = sizeof(temp)/sizeof(long long);
    // printf("The length of a long long is %llu\n", length);

    // long long unsigned aaaah = 0;
    // for (int j = 0; j < length; j++)
    // {
    //     aaaah += *(&temp[j]);
    // }
    // average = (float)times/number_iter;
    // printf("The average time was %f nanoseconds\n", average);
    // printf("The average time was %f nanoseconds\n", (float)aaaah/number_iter);
    
    return 0;
}
