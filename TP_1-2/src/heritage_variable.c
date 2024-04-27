#include <stdio.h> /* stderr, stdout, fprintf, perror */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h> /* exit */

int main(void)
{
    pid_t pid_fils1 = -1;
    pid_t pid_fils2 = -1;
    const char *royaume = "Aucun";

    royaume = "Carmélide";
    printf("(Léodagan, PID : %d, PPID : %d) voici mon royaume : %s. \n", getpid(),
    getppid(), royaume);

    pid_fils1 = fork();

    if (pid_fils1 != 0) 
    {
        pid_fils2 = fork();

        if (pid_fils2 == 0) 
        {
            printf("(Yvain, PID : %d, PPID : %d) voici mon royaume : %s. \n",
            getpid(), getppid(), royaume);
        }
    } 
    else 
    {
        printf("(Guenièvre, PID : %d, PPID : %d) voici mon royaume : %s. \n",
        getpid(), getppid(), royaume);
        royaume = "Logres";
        printf("(Guenièvre, PID : %d, PPID : %d) voici mon nouveau royaume : %s. \n",
        getpid(), getppid(), royaume);
    }
    wait(NULL);
    wait(NULL);
    sleep(50);
    exit(EXIT_SUCCESS);
}
