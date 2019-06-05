// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    // Your code here 

    // open file
    FILE * fp = fopen("text.txt", "w+");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    mkdir("subdir", 0755);


    // read file loop
    int c;
    while((c = fgetc(fp)) != EOF) 
    {
        putchar(c);
    }

    // writing to file from parent and child process

    fprintf(fp, "this came from the program\n");

    pid_t pid = fork();
    if (pid == 0) // Child process
    {

    fprintf(fp, "this came from the Child process\n");
    // fwrite(fp, "some stuff from child\n");
    }
    else          // Parrent process
    {
    wait(NULL);
    // fwrite(fp, "some stuff from parent\n");
    fprintf(fp, "this came from the Parent process\n");
        
    }
 
    char buff[128] = {0};

    // fgets(buff, 128, fp);
    read(fp, buff, 100);

    printf("Buffer has: \"%s\n\"", buff);

   
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);

    
    return 0;
}
