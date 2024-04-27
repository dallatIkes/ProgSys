#include <stdio.h>		/* stderr, stdout, fprintf, perror */
#include <unistd.h>		/* fork */
#include <sys/wait.h>		/* wait */
#include <stdlib.h>		/* exit */

int main(void){
    pid_t pid_fils1 = -1;
    int i=1;

    pid_fils1 = fork();
    fork();

    if (pid_fils1 != 0) 
    {
        i++;
        wait(NULL);
        wait(NULL);
    };
    i++;
    printf("Je suis %d et la valeur de i est : %d \n", getpid(), i);
    sleep(2);
    return EXIT_SUCCESS;
}