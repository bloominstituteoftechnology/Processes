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
    // Your code here    
	int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {  
    // list dates and permissions with total number 
    	 char *dates[] = {"ls", "-l", NULL};
    	 // lists all files in current directory
    	 char *lists[] = {"ls", "-1", NULL};
    	 // displays current directory


          // displays list of files in a folder
          // execl("/bin/ls", "ls", "-1", NULL);
          // will lost permission and dates
    	 // execv("/bin/ls", dates);

    	 // uses myprog as new process call
        execl("./myprog.exe", "2", NULL);
    } else {
    	int wc = waitpid(rc, NULL, 0);    
printf("%s\n", "Goodbye from parent");
    }


    return 0;
}
