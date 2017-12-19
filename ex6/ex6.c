// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define BILLION 1000000000L

int main(int argc, char* argv[])
{   
    long lc;
    printf("%s","How Far Down The Rabbit Hole, Will You Go!?\n=>");
    scanf("%ld", &lc);

    if(fork() == 0){
        struct timespec start, stop; 
        clock_gettime(CLOCK_REALTIME, &start); 
        
        for (int i = 0; i < lc; i++) { 
                if(i % 1 == 0) printf("%s\n","7");
                if(i % 2 == 0) printf("%s\n","77");
                if(i % 3 == 0) printf("%s\n","777");
                if(i % 4 == 0) printf("%s\n","7777");
                if(i % 5 == 0) printf("%s\n","77777");
                if(i % 7 == 0) printf("%s\n","777777");
                if(i % 8 == 0) printf("%s\n","7777777");
                if(i % 9 == 0) printf("%s\n","77777777");
                if(i % 10 == 0) printf("%s\n","777777777");             
                if(i % 11 == 0) printf("%s\n","7777777777");
                if(i % 12 == 0) printf("%s\n","77777777777");
                if(i % 13 == 0) printf("%s\n","777777777777");
                if(i % 14 == 0) printf("%s\n","7777777777777");
                if(i % 15 == 0) printf("%s\n","77777777777777");
                if(i % 16 == 0) printf("%s\n","777777777777777");
                if(i % 17 == 0) printf("%s\n","7777777777777777");  
            }      

        clock_gettime(CLOCK_REALTIME, &stop); 

        float seconds = stop.tv_sec - start.tv_sec; 
        double nano = stop.tv_nsec - start.tv_nsec; 
        
        if (start.tv_nsec > stop.tv_nsec) { --seconds; nano += BILLION;}
        printf("Per Cycle: %lf/ns | %lf/s\n", nano / (double)lc, seconds / (double)lc); 
        printf("Completed: %ld/ns | %0.3f/s\n", (long)nano, seconds + nano / BILLION); 
    }else{
        wait(0);
        printf("PROCESS FINISHED (%ld Cycles)\n", lc);
        return 0;
    }
}
