/*
Author Jonathan Jamel Holloway
Purpose // Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 
Date 11-8-18


https://repl.it/@codejoncode/Lambda-Exercise-5  completed  
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


#define MSGSIZE 16
/*^#define --> this is a directive it allows the definition of macros within your source code These macro defintions allow constant values to be declared for use throughout your code.... YOu generally use this syntax when creating constants that represent numbers strings or expressions.  */

char* msg1 = "hello world #1";  //allowed because of the define directive.  
char* msg2 = "hello world #2";//allowed because of the define directive.  
char* msg3 = "hello world #3";//allowed because of the define directive.  


int main(void) {
  char inbuf[MSGSIZE];
  int writepipe[2], readpipe[2], i; 
  /*p[2] is an array of int length 2 before '\0' i will be a plain int*/

  pid_t rc; 

  if (pipe(writepipe) == -1){
    fprintf(stderr, "write pipe failed\n");
  }

  if (pipe(readpipe) == 1){
    fprintf(stderr, "read pipe failed\n");
  }

  rc = fork(); 

  if(rc < 0){
    fprintf(stderr, "forking failed");
  } else if (rc > 0){
    //parent 
    close(readpipe[0]);/// close reading end [0] read [1] write 

    wait(NULL); //WAIT FOR CHILD TO FINISH

    /*READ STRING FROM CHILD*/

    close(writepipe[1]); // close writing end of writepipe 
    /* read the string from the child*/
    printf("WE are in the parent reading\n");
    for ( i = 0;  i < 3; i++){
        read(writepipe[0],inbuf, MSGSIZE); // READ Pipe
        printf("%s\n", inbuf); 
    }
    close(writepipe[0]); 
  } else {
    printf("WE are in the child writing\n");
     close(readpipe[1]);//close the writing end of the readpipe 
     write(writepipe[1], msg1, MSGSIZE);
     write(writepipe[1], msg2, MSGSIZE);
     write(writepipe[1], msg3, MSGSIZE);
     close(writepipe[1]);

     exit(0); //kill it 
  }



  return 0;
}



/*
Pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process.  

Pipe is a one way communication only i.e we can use a pipe such that One process write to the pipe and the other process reads from the pipe.  It opens a pipe which is an area of main memory that is treated as a "virtual file".   

The pipe can be used by the creating process as well as all it's child processes, for reading and writing. One process can write to this "virtual file" or pipe and another related process can read from it. 

If a process tries to read before something is written to the pipe, the process is suspended until something is written.   

The pipe system call finds the first two available positions in the processs open file table and allocates them for the read and write ends of the pipe. 

write()
write(int fildes, const void *buf, size_t nbytes);
int fildes = The file descriptor of where to write the output. You can eitehr use a file descriptor obatained from the open system call or you can use 0,1,2 to refer to standard input, standard output, or standard error, respectively. 

const void *buf   A pointer to a buffer to at least nbytes, which will be written to the file. 

size_tnbytes The number of bytes to write. If smaller than the provided buffer, the output is truncated.  

return value  Returns  the number of bytes that are written. If value is negative, then the system call returned an error. 


read() 

read(int fildes, void *buf, size_t nbytes);

The file descriptor of where to read the input. You can eitehr use a file descriptor obtained from the open system call or you can use 0, 1, 2 to refer to standard input, standard oupt or standard error respectively  

const void *buf   A character array where the read content will be stored. 

pretty much the same as write() 

*/
