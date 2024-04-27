#include <stdio.h> /* stderr, stdout, fprintf, perror */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* wait */
#include <stdlib.h> /* exit */

void singBoy(int i)
{
    i++;
    printf("Fils - %d Frère Jacques, Frère Jacques \n", i);
    sleep(2);
    printf("Fils - %d Dormez-vous ? Dormez-vous ? \n", i);
    sleep(2);
    printf("Fils - %d Sonnez les matines ! Sonnez les matines !\n", i);
    sleep(2);
    printf("Fils - %d Ding, daing, dong, Ding, daing, dong ...\n", i);sleep(2);
    exit(EXIT_SUCCESS);
}

void singMan(int i)
{
    wait(NULL);
    printf("Père - %d Sonnez les matines ! Sonnez les matines !\n", i);
    sleep(2);
    printf("Père - %d Ding, daing, dong, Ding, daing, dong ...\n", i);
    sleep(2);
}

int main(void)
{
    pid_t pid_fils = -1;
    int i = 1;

    printf("Père - %d Frère Jacques, Frère Jacques\n", i);
    sleep(2);
    printf("Père - %d Dormez-vous ? Dormez-vous ? \n", i);
    sleep(2);

    pid_fils = fork();

    if (pid_fils == 0) 
    {
        /* Code fils */
        singBoy(i);
    } 
    else 
    {
        /* Code père */
        singMan(i);
    }
    exit(EXIT_SUCCESS);
}
