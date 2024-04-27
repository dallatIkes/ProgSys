/********************************
 * Fichier orphan.c
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
    pid_t pid_fils = -1; /* Pour récupérer la valeur de retour de l'execution du fork */
    pid_fils = fork();   /* Création du processus fils */
    int i = 0;

    if (pid_fils == 0)
    {
        /* Code affecté au fils */
        for (i = 0; i < 10; i++)
        {
            printf("(fils, %d) .. mon père est %d \n", getpid(), getppid());
            sleep(2);
        }
        printf("(fils, %d) J'ai terminé \n", getpid());
        exit(EXIT_SUCCESS);
    }
    else
    { /* Code affecté au père */
        for (i = 0; i < 5; i++)
        {
            printf("(père, %d) ..\n", getpid());
            sleep(2);
        }
        printf("(père, %d) J'ai terminé... \n", getpid());
        exit(EXIT_SUCCESS);
    }
}
