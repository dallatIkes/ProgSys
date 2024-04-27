#include "include/std.h"
#include "include/prog_sys.h"

void SIGINT_handler(int sig)
{
    printf("Olé!\n");
}

int main()
{
    signal(SIGINT, SIGINT_handler);
    printf("=====================\n");
    printf("Lancement du compteur\n");
    printf("=====================\n");
    for (int count = 1; count <= 30; count++)
    {
        printf("%d\n", count);
        sleep(1);
    }
    printf("=======================\n");
    printf("Terminaison du compteur\n");
    printf("=======================\n");
}