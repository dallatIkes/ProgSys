/********************************
 * Fichier famille_wait2.c
 * Livre "Programmation d'applications système sous Linux"
 *
 * P. Alain, J. Chevelu, S. Le Maguer, V. Thion, B. Vozel
 *
 ********************************/
#include <stdio.h>    /* stderr, stdout, fprintf, perror */
#include <unistd.h>   /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h>   /* exit */

int main(void)
{
    pid_t pid_fils1 = -1;
    pid_t pid_fils2 = -1;

    pid_fils1 = fork();
    if (pid_fils1 == 0)
    {
        pid_fils2 = fork();
        printf("(pid:%d, ppid:%d) Do you do you Saint-Tropez (%d) (%d)\n", getpid(), getppid(), pid_fils1, pid_fils2);
        sleep(15);
        exit(EXIT_SUCCESS);
    }
    printf("(pid:%d, ppid:%d) Do you do you Saint-Tropez (%d) (%d)\n", getpid(), getppid(), pid_fils1, pid_fils2);
    wait(NULL);
    sleep(15);
    exit(EXIT_SUCCESS);
}
