/********************************
 * Fichier famille_wait1.c
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

    printf("Bonjour, je suis Léodagan (%d). \n", getpid());
    pid_fils1 = fork();
    if (pid_fils1 != 0)
    {
        pid_fils2 = fork();
        if (pid_fils2 == 0)
        {
            printf("Bonjour, je suis Yvain (%d), mon père est %d.\n", getpid(), getppid());
            sleep(15);
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        printf("Bonjour, je suis Guenièvre (%d), mon père est %d.\n", getpid(), getppid());
        sleep(15);
        exit(EXIT_SUCCESS);
    }
    wait(NULL);
    sleep(15);
    exit(EXIT_SUCCESS);
}
