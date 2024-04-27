#include <stdio.h> /* stderr, stdout, fprintf, perror */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h> /* exit */

int main(void)
{
    pid_t pid_fils = -1; /* Pour récupérer la valeur de
    * retour de l’execution du fork */
    pid_fils = fork();

    if (pid_fils != 0) 
    {
        /* Code exécuté par le père */
        printf("(%d) We can light it up, up, up \n", getpid());
    } 
    else 
    {
        /* Code exécuté par le fils */
        printf("(%d) So they can’t put it out, out, out \n", getpid());
    }
    wait(NULL);
    exit(EXIT_SUCCESS);
}
