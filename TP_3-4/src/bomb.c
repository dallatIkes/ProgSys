/********************************
 * Fichier bomb.c
 * Livre "Programmation d'applications système sous Linux"
 *
 * P. Alain, J. Chevelu, S. Le Maguer, V. Thion, B. Vozel
 *
 ********************************/
#include <stdio.h>     /* printf */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* exit */
#include <sys/errno.h> /* errno */
#include <string.h>    /* strerror */

int main(void)
{
    int fork_return_value;

    errno = 0; /* Initialisation de errno */

    do
    {
        fork_return_value = fork();
        if (fork_return_value == 0)
        {
            printf("%d\n", getpid());
            exit(EXIT_SUCCESS);
        }
    } while (fork_return_value != -1);

    printf("errno:%d, %s\n", errno, strerror(errno));
    /* voir man 2 intro et man strerror */

    exit(EXIT_SUCCESS);
}
