// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

//https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
// pipe() is used for passing information from one process to another. pipe() is unidirectional


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

// int main(void)
// {
//     // Your code here
    
//     return 0;
// }


//example 

int main() 
{
    //use two pipes
    //first pipe sends input string from parent
    //second pipe sends concatatenated string from child

    int fd1[2];  //store two ends of first pipe
    int fd2[2];  //store two ends of second pipe

    char fixed_str[] = " | hello message";
    char input_str[100];
    pid_t p; // pid_t assigns the data type as proccess id

    if (pipe(fd1) == -1)
    {
        fprintf(stderr, "pipe failed");
        return 1;  //return 1
    }
    if (pipe(fd2) == -1)
    {
        fprintf(stderr, "pipe failed");
        return 1;
    }

    scanf("%s", input_str);
    p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork failed");
        return 1;
    }

    // parent process
    else if (p > 0)
    {
        char concat_str[100];
        close(fd1[0]); //close reading end of first pipe

        //write input string and close writing end of first pipe

        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);

        //wait for child to send a string
        wait(NULL);

        close(fd2[1]); // close writing end of second pipe

        //read string from child, print it and close reading end
        read(fd2[0], concat_str, 100);
        printf("concatenated string (parent process) | %s\n", concat_str);
        close(fd2[0]);
    }
    // child process
    else
    {
        close(fd1[1]);  // close the writing end of the first pipe

        //read string using first pipe
        char concat_str[100];
        read(fd1[0],concat_str, 100);

        //concatenate a fixed string with it
        int k = strlen(concat_str);
        unsigned int a = strlen(fixed_str);
        unsigned int i;
        for (i = 0; i<a; i++)
            concat_str[k++] = fixed_str[i];
        
        concat_str[k] = '\0'; //string ends with '\0'

        //close both reading ends

        close(fd1[0]);
        close(fd2[0]);

        //write concatenated string and close writing end
        write(fd2[1], concat_str, strlen(concat_str)+1);
        close(fd2[1]);

        exit(0);
    }
}

