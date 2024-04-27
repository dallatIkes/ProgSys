#include <stdio.h>    /* stderr, stdout, fprintf, perror */
#include <unistd.h>   /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h>   /* exit, atoi */
#include <time.h>

int main(int argc, char *argv[])
{
    pid_t pid_fils = -1;
    int temps_traitement_simule = (rand() % 10) + 1;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        pid_fils = fork();
        if (pid_fils == 0)
        {
            sleep(temps_traitement_simule);
            exit(EXIT_SUCCESS);
        }
    }
    wait(NULL);
}