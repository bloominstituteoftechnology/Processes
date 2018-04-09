// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char text[100];
    FILE *fp;

    fp = fopen("text.txt", "r");

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork() failed\n");
    }
    else if (rc == 0)
    {
        // fp = fopen("text.txt", "r");
        fread(text, 8, sizeof(text), fp);
        printf("Child text read: %s", text);
        // fclose(fp);
    }
    else
    {
        // fp = fopen("text.txt", "r");
        fread(text, 8, sizeof(text), fp);
        printf("Parent text read: %s", text);
        // fclose(fp);
    }

    fclose(fp);

    /*
        It looks like trying to write the file concurrently causes an error
        in reading:
        case when parent is first:
        Parent text read: This is parent string!
        Child text read: �hK�

        case when child is first:
        $ Child text read: Ș���./ex2
        Parent text read: This is parent string!

        But if you properly open and close the file in each parent/child:
        $ ./ex2
        Parent text read: This is parent string!
        Child text read: This is parent string!

        Because it copies, the file pointer doesn't advance to the child string
        but just copies the parent string twice.

        Because of fork(), do not think it is possible to have each process
        print their respective strings.
    */

    return 0;
}
