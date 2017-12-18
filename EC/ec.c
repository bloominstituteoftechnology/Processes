// Write an additional program that creates two processes P1 and P2.
// P1 should accept a string from standard input and passes it to P2. 
// P2 should concatenate the received string with another string and 
// sends it back to P1 for printing.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#define LINE_MAX 50

int main(void) {
  char inbuf[LINE_MAX];
  // char result[LINE_MAX];
  
  int sp[2];
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, sp) < 0) {
      fprintf(stderr, "socketpair failed\n");
      exit(1);
  }

  int rc = fork();
    if (rc < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) {
      char output[LINE_MAX];
      strcpy(output, "Hello ");
      read(sp[1], inbuf, LINE_MAX);
      strcat(output, inbuf);
      write(sp[1], output, LINE_MAX);
    } else {
      printf("Enter a string: ");
      fgets(inbuf, LINE_MAX, stdin);
      write(sp[0], inbuf, LINE_MAX);
      // int wc = waitpid(rc, NULL);
      read(sp[0], inbuf, LINE_MAX);
      
      printf("%s", inbuf);
      wait(NULL);
    }

  return 0;
}