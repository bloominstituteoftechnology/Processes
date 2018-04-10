#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int p1[2];
    int p2[2];

    if (pipe(p1) < 0 || pipe(p2) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork() failed\n");
    }

    else if (rc == 0) /* p2 */
    {
        close(p1[1]); /* close p1 write pipe */
        close(p2[0]); /* close p2 read pipe */

        char msg[512];
        char name[128];

        read(p1[0], name, sizeof(name));

        strcat(msg, "Hello there ");
        strcat(msg, name);
        strcat(msg, "! ");
        strcat(msg, "My name is Aida.");

        write(p2[1], msg, sizeof(msg));
    }

    else /* p1 */
    {
        close(p1[0]); /* close p1 read pipe */
        close(p2[1]); /* close p2 write pipe */

        char input_str[256];

        printf("Enter your name: ");
        fgets(input_str, sizeof(input_str), stdin);

        int input_len = strlen(input_str);
        input_str[input_len - 1] = '\0';

        write(p1[1], input_str, sizeof(input_str));

        waitpid(rc, NULL, 0);

        char inbuf[512];

        read(p2[0], inbuf, 512);
        printf("%s\n", inbuf);
    }

    return 0;
}
