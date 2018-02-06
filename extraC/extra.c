// Write an additional program that creates two processes P1 and P2.
// P1 should accept a string from standard input and passes it to P2.
// P2 should concatenate the received string with another string and sends it back to P1 for printing.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MSGSIZE 16


int main()
{
  char buffer[MSGSIZE]; // a buffer that will hold the incoming data that is being written
  int p[3];             // array to hold the read and write file descriptors that are used by the pipe

  if (pipe(p) < 0)
  {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }

  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  { // Child process
    char *msg2 = "world\n";
    char *result;

    read(p[1], buffer, MSGSIZE);
    strcpy(result, buffer);
    strcat(result, msg2);
    write(p[2], result, MSGSIZE);
  }
  else
  { // Parent Process
    char *msg1 = "hello ";

    write(p[1], msg1, MSGSIZE);
    int wc = waitpid(rc, NULL, 0);
    read(p[2], buffer, MSGSIZE);
    printf("%s \n", buffer);
  }

  return 0;
}