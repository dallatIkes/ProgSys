#include <stdio.h>    /* stderr, stdout, fprintf, perror */
#include <unistd.h>   /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h>   /* exit */

int main()
{
    pid_t pid_fils = -1;

    pid_fils = fork();

    for (int i = 0; i < 3; i++)
    {
        if (pid_fils == 0)
        {
            pid_fils = fork();
        }
    }
    wait(NULL);
    sleep(15);
    exit(EXIT_SUCCESS);
}