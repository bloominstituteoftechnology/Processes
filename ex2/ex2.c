// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
//
//https://stackoverflow.com/questions/11733481/can-anyone-explain-a-simple-description-regarding-file-descriptor-after-fork
//It's important to distinguish between the file descriptor, which is a small integer
//that the process uses in its read and write calls to identify the file, and
//the file description, which is a structure in the kernel.
//The file offset is part of the file description. It lives in the kernel.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;
    // char str[999];
    // FILE *file;
    char str;
    char c;

    // int x = 100;
    // int *p = &x;

    // file = fopen("./text.txt", "rw+");

    // if (file)
    // {
    //     while (fscanf(file, "%s", str) != EOF)
    //         printf("%s \n", str);
    //     fclose(file);
    // }
    // printf("Current directory: %s \n", GetCurrentDirectory());
    fp = fopen("./text.txt", "r+");

    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }

    printf("here is after fopen called then fork:\n");
    printf("Before fork is called : ( pid: %d)\n", (int)getpid());

    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    /*
    The parent process receives the PID of the child process it just spawned, 
    while the child process receives 0 if the fork() call was successful.
    */
    else if (rc == 0)
    { // child process satisfies this branch
        // *p /= 5;
        // printf("Child here x: %d address of x : %p (pid: %d) \n", *p, x, (int)getpid());
        printf("Child here : (pid: %d) \n", (int)getpid());

        //write to the file
        printf("Enter the string for child: \n");
        scanf("%s", &str);
        fprintf(fp, "%s", &str);
    }
    else
    { //parent processing
        // int wc = 0;

        //write to the file for parent processing
        printf("Enter the string for parent: \n");
        scanf("%s", &str);
        fprintf(fp, "%s", &str);
        printf("parent here : (pid: %d) \n", (int)getpid());
        // printf("parent here x: %d address of x : %p (pid: %d) of child %d\n", *p, x, (int)getpid(), rc);
    }
    // //write to the file
    // printf("Enter the string to write: \n");
    // scanf("%s", &str);
    // fprintf(fp, "%s", &str);

    fclose(fp);

    return 0;
}
