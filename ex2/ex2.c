// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_contents(char* filename, int pid)
{
    FILE *file;

    // Open file
    file = fopen(filename, "r");
    int character;

    printf("\nprint_contents called from pid: %d\n", pid);
    
    while(1)
    {
        character = fgetc(file);
        if (feof(file))
        {
            break;
        }
        printf("%c", character);
    }
    printf("\n");
    fclose(file);
}

void append_to_file(char* filename, char* str)
{
    FILE *file;
    file = fopen(filename, "a");
    fprintf(file, "%s", str);
    fclose(file);
}

int main(void)
{
    print_contents("text.txt", (int) getpid());
    printf("\n--- BEGIN FORK ---\n");
    // Create a fork
    int child_process = fork();
    if (child_process < 0)
    {
        // Failure to fork
        fprintf(stderr, "Failed to fork!\n");
        exit(1);
    } 
    else if (child_process == 0)
    {
        printf("In the child process, pid: %d \n", (int) getpid());
        append_to_file("text.txt", "!");
        print_contents("text.txt", (int) getpid());
    } 
    else
    {
        printf("In the parent process, pid: %d \n", (int) getpid());
        print_contents("text.txt", (int) getpid());
    }

    return 0;
}
