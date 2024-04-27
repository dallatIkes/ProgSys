#include "include/std.h"
#include "include/prog_sys.h"

void initRand()
{
    FILE *urand = fopen("/dev/random", "r");
    unsigned int seed;
    fread(&seed, sizeof(int), 1, urand);
    fclose(urand);
    // fprintf(stderr, "seed : %u\n", seed);
    srand(seed);
}

void sigCapture(int sig)
{
    printf("\033[0;34m");
    printf("\tPère : Je viens de recevoir le signal : %s\n\n", strsignal(sig));
    printf("\033[0;37m");
}

int main()
{
    pid_t pid_fils = -1;

    /* Code du père */
    for (int i = 1; i <= 31; i++)
    {
        signal(i, sigCapture);
    }

    pid_fils = fork();

    /*Code du fils */
    if (pid_fils == 0)
    {
        initRand();
        for (int i = 0; i < 50; i++)
        {
            int sig = 9;
            while (sig == 9 || sig == 19)
            {
                sig = (rand() % 31) + 1;
            }
            kill(getppid(), sig);
            printf("\033[0;36m");
            printf("Fils : Je viens d'envoyer le signal : %s\n", strsignal(sig));
            printf("\033[0;37m");
            sleep(1);
        }
        int sig = 9;
        kill(getppid(), sig);
        printf("\033[0;36m");
        printf("Fils : Je viens d'envoyer le signal : %s\n", strsignal(sig));
        printf("\033[0;37m");
        exit(EXIT_SUCCESS);
    }

    /* Boucle infinie d'attente de capture de signaux*/
    while (1)
    {
    }
}