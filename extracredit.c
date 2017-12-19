#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 64

int main()
{
    // Your code here
    char inbuf[MSGSIZE];
    char concatbuf[128];
    char outbuf[512];
    char str[64];
    int p[2];
    char* msg2;
    msg2 = " is a cool person!";
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Give name\n");
        scanf("%s", str);
        write(p[1], str, MSGSIZE);
        read(p[0], outbuf, 512);
        printf("%s\n", outbuf);
    } else {
        read(p[0], inbuf, MSGSIZE);
        snprintf(concatbuf, sizeof concatbuf, "%s%s", inbuf, msg2);
        
        write(p[1], concatbuf, 256);
    }    
    return 0;
}
