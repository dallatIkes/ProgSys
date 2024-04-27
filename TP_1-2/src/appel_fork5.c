#include <stdio.h> /* stderr, stdout, fprintf, perror */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h> /* exit */

int main(void)
{
    pid_t pid_fils1 = -1;
    pid_t pid_fils2 = -1;
    pid_t pid_fils3 = -1;

    pid_fils1 = fork();
    pid_fils2 = fork();
    pid_fils3 = fork();

    printf("(%d) Alors on danse (%d) (%d) (%d)\n", getpid(), pid_fils1, pid_fils2,
    pid_fils3);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    sleep(50);
    exit(EXIT_SUCCESS);
}
