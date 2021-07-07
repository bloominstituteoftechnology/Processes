#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();
    printf("Hello %d\n", pid);
    return 0;
}