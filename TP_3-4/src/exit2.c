/********************************
 * Fichier exit2.c
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
    pid_t pid_fils = -1;
    pid_fils = fork();
    int status;

    if (pid_fils == 0)
    {
        sleep(2);
        printf("Monsieur le Président, je vous fais une lettre\n");
        exit(EXIT_SUCCESS);
    }
    wait(&status);
    printf("que vous lirez peut-être si vous avez le temps\n");
    exit(EXIT_SUCCESS);
}
