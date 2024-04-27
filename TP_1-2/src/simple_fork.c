#include <stdio.h> // stderr, stdout, fprintf, perror 
#include <unistd.h> // fork 
#include <sys/wait.h> // wait 
#include <stdlib.h> // exit 

int main(void)
{
    pid_t pid_fils = -1; /* Variable destinée à récupérer la valeur de retour de l’execution du fork */
    pid_fils = fork();
    /* Si echec d’execution du fork (p.e. table des PCB pleine) */
    if (pid_fils == -1) 
    {
        perror("Echec du fork\n"); /* Affichage erreur sur terminal */
        exit(EXIT_FAILURE); /* Sortie du programme, en erreur */
    }
    /* Code exécuté quand l’execution de fork n’est pas en échec */
    printf("(%d) All you need is love \n", getpid());
    printf("My father's PID is : (%d) \n", getppid());
    sleep(50); /* Suspension du processus pendant 15 sec */
    return EXIT_SUCCESS; /* Sortie du programme, en succès */
}