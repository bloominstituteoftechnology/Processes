#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
    int rc = folk();

    if(rc < 0){
        fprintf(stderr, "Folk failed\n");
        exit(1);
    }
    else if (rc == 0){
        execl("/bin/ls", "ls", NULL);
    }
    else{
        int wc = waitpid(rc, NULL, 0);
        printf("Parent process - pid: %d\n", (int)getpid());
    }
    return 0;
}