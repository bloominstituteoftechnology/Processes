#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int MSGSIZE = 100;
    int BUFSIZE = 1000;
    char* cat = ".....that's what she said.";
    char user_input[32];
    char inbuf[32];
    char outbuf[MSGSIZE];
    char buf[MSGSIZE];
    int p[2];
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        printf("error man");
        exit(1);
    } else if (rc == 0) {
        printf("Enter da message: ");
        fgets(user_input, 32, stdin);
        if ((strlen(user_input) > 0) && (user_input[strlen(user_input) - 1] == '\n')) {
            user_input[strlen (user_input) - 1] = '\0'; 
        }
        write(p[1], user_input, MSGSIZE);
        read(p[0], outbuf, BUFSIZE);
        printf("%s\n", outbuf);
    } else {
        read(p[0], inbuf, sizeof(user_input));
        snprintf(buf, sizeof buf, "%s%s", inbuf, cat);
        write(p[1], buf, BUFSIZE);
    }
    return 0;
}