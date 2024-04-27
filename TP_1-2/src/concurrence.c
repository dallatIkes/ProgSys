#include <stdio.h> // stderr, stdout, fprintf, perror 
#include <unistd.h> // fork 
#include <sys/wait.h> // wait 
#include <stdlib.h> // exit 

int main(void)
{
    int i;
    for (i = 1; i < 30000; i++) 
    {
        printf("(%d) %d km ..., %d km à pied, ca use les souliers. \n", getpid(), i, i);
        //sleep(1);
    }
    return (EXIT_SUCCESS);
}
