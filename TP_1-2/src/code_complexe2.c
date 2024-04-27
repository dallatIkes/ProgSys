#include <stdio.h>		/* stderr, stdout, fprintf, perror */
#include <unistd.h>		/* fork */
#include <sys/wait.h>		/* wait */
#include <stdlib.h>		/* exit */

int main(void){
    pid_t pid_fils1 = -1, pid_fils2 = -1;
    int i=1;

    pid_fils1 = fork();

    if (pid_fils1 != 0) 
    {
        i=i+1;
        wait(NULL);
        wait(NULL);
    }
    else
    {
        fork();
        i=i-1;
        wait(NULL);
        printf("Je suis %d\npid_fils1 : %d\npid_fils2 : %d\ni : %d \n", getpid(), pid_fils1, pid_fils2, i);  
        sleep(15);
        exit(EXIT_SUCCESS);
    };
    pid_fils2 = fork();
    i=i+1;
    printf("Je suis %d\npid_fils1 : %d\npid_fils2 : %d\ni : %d \n", getpid(), pid_fils1, pid_fils2, i);  
    sleep(15);
    return EXIT_SUCCESS;
}
