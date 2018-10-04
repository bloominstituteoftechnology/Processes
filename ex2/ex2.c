// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// The parent first can update the file then the child updates after the parent.
// They both can access the file descriptor since they were both able to perform an operation to that specific file
// which in this case is text.txt
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(void) {
    FILE *fp;

    fp = fopen("text.txt", "w+");
    fprintf(fp, "%s %d\n", "Before forking", getpid());
    if(!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    int pid = fork();
    fprintf(fp, "%s %d\n", "After forking", getpid());

    if (pid < 0) {
        exit(1);
    }
    else if (pid == 0) {
        fprintf(fp, "%s %d\n", "Child file", getpid());
    }
    else {
        fprintf(fp, "%s %d\n", "Parent file", getpid());
    }
    fclose(fp);
    return 0;
}

// Code that I worked with Vim
// int main(void)
// {
//     // Your code here
//     FILE *fp;
//     fp = fopen("text.txt", "w+");
//     printf("Before forking pid: %d\n", getpid());
//     fprintf(fp, "%s %s %s %s %d\n", "File", "write", "before", "fork", getpid());
//     int pid = fork();
//     if (pid < 0) //fork failed
//     {
//         exit(1);
//     }
//     else if (pid == 0) //child process
//     {
//         printf("AFTER forking CHILD pid: %d\n", getpid());
//         fprintf(fp, "%s %s %d\n", "Child-File", "write", getpid());
//     }
//     else
//     {
//         printf("AFTER forking PARENT pid: %d\n", getpid());
//         fprintf(fp, "%s %s %d\n", "Parent-File", "write", getpid());
//     }
//     fclose(fp);
// }
