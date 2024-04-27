#include <std.h>
#include <prog_sys.h>
#include <colors.h>

void Solutiend(int);

void initRand()
{
    FILE *urand = fopen("/dev/random", "r");
    unsigned int seed;
    fread(&seed, sizeof(int), 1, urand);
    fclose(urand);
    // fprintf(stderr, "seed : %u\n", seed);
    srand(seed);
}

int a;
int b;

int main(int argc, char *argv[])
{
    if (argc == 2 && atoi(argv[1]) >= 0)
    {
        initRand();
        signal(SIGALRM, Solutiend);
        signal(SIGINT, Solutiend);
        a = rand() % 11;
        b = rand() % 11;
        int answer;
        int time = atoi(argv[1]);
        printf("Vous avez %d seconde(s) pour résoudre la multiplication suivante : \n", time);
        printf("%d x %d = ", a, b);
        if (time != 0)
        {
            alarm(time);
            scanf("%d", &answer);
            if (answer == a * b)
            {
                printf(GREEN);
                printf("Bravo! \n");
                printf(WHITE);
            }
            else
            {
                printf(RED);
                printf("Dommage, mauvaise réponse\n");
                printf(WHITE);
            }
        }
        else
        {
            printf("\nLa solution était : %d\n", a * b);
        }
    }
    else
    {
        printf(RED);
        printf("/!\\ Erreur : veuillez renseignez un unique paramètre /!\\ \n");
        printf(WHITE);
    }

    return EXIT_SUCCESS;
}

void Solutiend(int sig)
{
    printf("\nLa solution était : %d\n", a * b);
    exit(EXIT_SUCCESS);
}