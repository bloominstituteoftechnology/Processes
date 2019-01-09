// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0) {
      printf("execv\n");
      char * argv_list[] = {"ls","-lart","/home",NULL};

      execv("/bin/ls", argv_list);
      exit(0);

      printf("execl");
      int ret = execl("/bin/ls", "ls", "-l", NULL);
      printf("%d", ret);
      exit(0);
    } else {
      printf("execle\n");
      execle("/bin/ls", "ls", "-l", NULL);
      exit(0);
    }

    return 0;
}
