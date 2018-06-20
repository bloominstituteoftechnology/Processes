// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// '/bin/ls' is what I know as just linux command 'ls', which lists contents of the directory.

/* exec() have quite a family:
execv(path, null terminated array of character pointers);
execl(path, describes a list of one or more pointers to null-terminated strings that represent argument list available to the executed program);
execle(specific environment of executed program via envp, array of pointers to null-terminated strings)

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0)
    {
        exec("/bin/ls");
    }
    else
    {
        exec("/bin/ls");
    }
    return 0;
}
