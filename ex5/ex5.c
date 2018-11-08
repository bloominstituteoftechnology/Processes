// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
  int fd[2];
  char buffer[20];

  if ( pipe(fd) < 0 ) {
    perror( "pipe" );
    exit( 1 );
  }

  switch( fork() ) {
    case -1:
      perror( "fork" );
      exit( 1 );

    case 0:
      /*child process*/
      close(fd[1]);
      fork();
      ssize_t count = read( fd[0], buffer, sizeof(buffer)-1 );
      if ( count <= 0 ) {
        perror( "read" );
        exit( 1 );
      }
      buffer[count] = '\0';
      printf( "Child read message from parent: %s\n", buffer );
      printf( "Child read message from parent: %s\n", buffer );
      printf( "Child read message from parent: %s\n", buffer );
      exit(1);

    default:
      /*parent process*/
      close(fd[0]);

      size_t length1 = strlen( msg1 );
      write( fd[1], msg1, length1 );
      fork();
      size_t length2 = strlen( msg2 );
      write( fd[1], msg2, length2 );
      fork();
      size_t length3 = strlen( msg3 );
      write( fd[1], msg3, length3 );
      fork();
      break;
  }

    return 0;
}
