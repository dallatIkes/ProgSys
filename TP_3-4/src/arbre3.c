#include <stdio.h>    /* stderr, stdout, fprintf, perror */
#include <unistd.h>   /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h>   /* exit */

int main()
{
    pid_t pid_fils1 = -1;
    pid_t pid_fils2 = -1;
    pid_t pid_fils3 = -1;

    pid_fils1 = fork();

    if (pid_fils1 == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            if (pid_fils1 == 0)
            {
                pid_fils1 = fork();
            }
        }
    }
    else
    {
        pid_fils2 = fork();
        if (pid_fils2 != 0)
        {
            pid_fils3 = fork();
        }
        sleep(15);
        exit(EXIT_SUCCESS);
    }

    wait(NULL);
    sleep(15);
    exit(EXIT_SUCCESS);
}