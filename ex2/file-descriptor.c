
//########################################################################################
// https : //stackoverflow.com/questions/11733481/can-anyone-explain-a-simple-description-regarding-file-descriptor-after-fork
//It's important to distinguish between the file descriptor, which is a small integer
//that the process uses in its read and write calls to identify the file, and
//the file description, which is a structure in the kernel.
//The file offset is part of the file description. It lives in the kernel.
//########################################################################################
//
//http://www.codeman.net/wp-content/uploads/2014/04/APUE-3rd.pdf
// "Advanced Programming in the Unix Environment", 2nd edition, By W. Richard Stevens
//Section 8.3 fork function.
//The new process created by fork is called the child process.
//This function is called once but returns twice. The only difference in the returns
// is that the return value in the child is 0, whereas the return value
//in the parent is the process ID of the new child.
//Both the child and the parent continue executing with the instruction that
//follows the call to fork. The child is a copy of the parent.
//For example, the child gets a copy of the parent’s data space, heap, and stack.
// ***Note that this is a copy for the child;
// ***the parent and the child do not share these portions of memory. The parent and
// ***the child do share the text segment, however (Section 7.6).
//
//########################################################################################
//########################################################################################

// #include <unistd.h>
// #include <fcntl.h>
// #include <sys/wait.h>

// int main(void)
// {
//   int fd;

//   fd = open("output", O_CREAT | O_TRUNC | O_WRONLY, 0666);

//   if (!fork())
//   {
//      /* child */
//      write(fd, "hello ", 6);
//      _exit(0);
//   }
//   else
//  {
//      /* parent */
//      int status;

//    wait(&status);
//    write(fd, "world\n", 6);
//  }
//}

//########################################################################################
//########################################################################################
// figure 8.1 page 230 book example

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
// #include <apue.h>

//https://stackoverflow.com/questions/7058779/where-is-function-err-sys-defined
//err_sys is used in the book "UNIX Network Programming:
//The sockets networking API" by Richard Stevens. It's not something common,
// as far as I know.  Place this on top of your code:

void err_sys(const char *x)
{
  perror(x);
  exit(1);
}

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
  int var; /* automatic variable on the stack */
  pid_t pid;
  var = 88;
  if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    err_sys("write error");
  printf("before fork\n"); /* we don’t flush stdout */
  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {            /* child */
    globvar++; /* modify variables */
    var++;
    printf("Child pid is =: %ld, globale varible =: %d, child variable is =: %d\n", (long)getpid(), globvar, var);
  }
  else
  {
    sleep(2); /* parent */
    printf("Parent pid is =: %ld, globale varible =: %d, Parent variable is =: %d\n", (long)getpid(), globvar, var);
  }

  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

  exit(0);
}
