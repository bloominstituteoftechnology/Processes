// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    // Your code here    

    int rc = fork();
    
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){

        printf("hello, child here (pid: %d) \n", (int) getpid());
       char *myargs[2];
       myargs[0] = strdup("/bin/ls");
       myargs[1] = NULL;
       execvp(myargs[0], myargs);
        execl("/bin/ls", "ls");
        //execle("/bin/ls", "ls");
    } else {
          int wc = waitpid(rc, NULL, 0);
          printf("Finished\n");
    }


//      int rc = fork();
//     if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//        printf("hello, child here (pid: %d) \n", (int) getpid());
//        char *myargs[2];
//        myargs[0] = strdup("/bin/ls");
//        myargs[1] = NULL;
//        execvp(myargs[0], myargs);
//    // execle("/bin/ls","ls");
//     } else {
//         int wc = waitpid(rc, NULL, 0);
//         printf("DOne\n");
// //        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
//     }
//     return 0;
    
    return 0;
}
