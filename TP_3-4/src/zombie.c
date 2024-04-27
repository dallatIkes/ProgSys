#include <stdio.h>    /* stderr, stdout, fprintf, perror */
#include <unistd.h>   /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h>   /* exit */

int main()
{
    pid_t pid_fils = -1; /* Pour récupérer la valeur de retour de l'execution du fork */
    pid_fils = fork();   /* Création du processus fils */

    if (pid_fils == 0)
    {
        // sleep(20);
        printf("Bonjour, je suis le fils !\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        sleep(20);
        printf("Bonjour, je suis le père !\n");
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}