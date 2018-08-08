// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *file = fopen("text.txt", "a+");

    int fork_process = fork();

    if (fork_process < 0)
    {
        fprintf(stderr, "Something went wronk forking %d process\n", (int)getpid());
    }
    else if (fork_process == 0)
    {
        printf("=== CHILD_1 HELLO ===\n");
        fprintf(file, "%s\n", "Writing from Child");
        printf("File closed\n");
        fclose(file);
        printf("=== CHILD_2 BYE ===\n");
    }
    else
    {
        printf("=== PARENT_1 HELLO ===\n");
        fprintf(file, "%s\n", "Writing from Parent");
        printf("File closed\n");
        fclose(file);
        printf("=== PARENT_2 BYE ===\n");
    }

    return 0;
}

/*
******************** First commit **************************
*********  OUTPUT  *********
TERMINAL
=== PARENT_1 HELLO ===
=== PARENT_2 BYE ===
=== CHILD_1 HELLO ===
=== CHILD_2 BYE ===

text.txt
Writing from Parent
Writing from Child

I can infer that
1. Due to the fact tha the file were open before the fork() were inviked: both files have access to this File.
2. Both files can perform the operations allowed to the File, in this particular example "a+ (Read and Write)"

******************** Second commit **************************
ADD a call to fclose() in both the parent and child pricess.

    Even tought the fclose() is called on one of the processes, the other
    that executes after still has access to the File.

    I understand that as if every single processes 'close' its own access to the File.

*/
