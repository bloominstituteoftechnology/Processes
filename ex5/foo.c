#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

/* Read characters from the pipe and echo them to stdout. */

void
rPipe (int file)
{
  FILE *stream;
  int c;
  stream = fdopen (file, "r");
  while ((c = fgetc (stream)) != EOF)
    putchar (c);
  fclose (stream);
}

/* Write some random text to the pipe. */

void
wPipe (int file, char* s)
{
  puts(s);
  FILE *stream;
  stream = fdopen (file, "w");
  fclose (stream);
}

int
main (void)
{
  int pid;
  int p[2];
  pipe(p);
  /* Create the child process. */
  pid = fork ();
  if (pid == 0)
    {
      
        close (p[0]);
        wPipe (p[1], "boom");
    }else{
      wait(0);
      if(fork() == 0){
      close (p[1]);
      rPipe (p[0]);
      }else{
        close (p[0]);
        char* s = "WORLD";
        wPipe (p[1], s);
      }
     
      return EXIT_SUCCESS;
    }
}