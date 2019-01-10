// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *str = "Gotta find a way, a better way\n";
    printf("%s", str);
    int rc = fork();
    if(rc < 1)
    {
        char *str2 = "when I'm there.\n";
        printf("%s", str2);
        printf("PID: %d\n", getpid());
        rc = 1;
    } else
    {
        sleep(1);
        printf("\"Nirvana - Territorial Pissings\"\n");
        printf("PID: %d\n", getpid());
    }

    return 0;
}
