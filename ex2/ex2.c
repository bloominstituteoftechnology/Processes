// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void wfile(FILE **file, char *name) 
{
    if(fork() > 0) fprintf(*file, "%s%s\n", "=>WRITTEN BY ", name);
}
void rfile(FILE **file)
{
    char lines[150];
    wait(0);
    while(!feof(*file)){
        fgets(lines, 150, *file);
        printf("Line: %s\n", lines);
    }
}

int main(int argc, char* argv[])
{
    int cpid = fork();
    printf("pid: %d\n",cpid);
    FILE *file = fopen("./text.txt", "a+");
    
    if(cpid == 0) {
        puts("CHILD PROCESS\n");
        wfile(&file, "CHILD");
    }else{
         wait(0);
        puts("PARENT PROCESS\n");
        wfile(&file, "PARENT");
        rfile(&file);
    }

    fclose(file);
    return 0;
}
