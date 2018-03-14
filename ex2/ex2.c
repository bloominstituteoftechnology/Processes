// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;

    char buffer[255];
    fp = fopen("text.txt", "a+");
    pid_t rc = fork();

    if (rc == 0)
    {
        // This is the child
        fgets(buffer, 255, fp);
        printf("child read: %s\n", buffer);
    }
    else
    {
        // This is the parent
        sleep(1);
        printf("parent woke up!\n");

        fgets(buffer, 255, fp);
        printf("parent read: %s\n", buffer);
    }

    // while (1)
    // {
    //     c = fgetc(fp);
    //     if (feof(fp))
    //     {
    //         break;
    //     }
    //     printf("%c", c);
    // }

    // if (pid == 0)
    // {
    //     printf("%d: Child process!\n", (int)getpid());
    //     char child_str[] = "This is the child string!\n";
    //     fwrite(child_str, 1, sizeof(child_str), fp);
    // }
    // else
    // {
    //     printf("%d: Parent process!\n", (int)getpid());
    //     char parent_str[] = "This is parent string!\n";
    //     fwrite(parent_str, 1, sizeof(parent_str), fp);
    // }

    // fclose(fp);

    return 0;
}
