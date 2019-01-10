// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?
//
// I think there are variants for te same call for returning different
// values and or handling differetn options.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Calling them all at once doesn't print the statements in order, but does
// do the processes in order

int main(void)
{
    pid_t pid = fork();

    if (pid == 0) {
      printf("\n---------------\nexecv\n---------------\n");
      char * argv_list[] = {"ls","-lart","/home",NULL};

      execv("/bin/ls", argv_list);
      exit(0);

      char* envp[] = {"/usr/lib", 0};
      printf("\n---------------\nexecl\n---------------\n");
      execl("/bin/ls", "ls", "-l", "-a", 0, envp);
      // printf("%d", ret);
      exit(0);
    } else {
      printf("\n---------------\nexecle\n---------------\n");
      char* envp[] = {"/usr/lib", 0};
      execle("/bin/ls", "ls", "-l", "-a", 0, envp);
      exit(0);
    }

    return 0;
}
