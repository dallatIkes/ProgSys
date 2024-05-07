/********************************
 * Fichier exit.c
 * Livre "Programmation d'applications système sous Linux"
 *
 * P. Alain, J. Chevelu, S. Le Maguer, V. Thion, B. Vozel
 *
 ********************************/
#include <colors.h>
#include <prog_sys.h>
#include <std.h>

void *affiche(void *arg);

int main(int argc, char *argv[])
{
    pthread_t thr1, thr2;
    int i, returnValue;

    // Utilisation du prg
    if (argc != 4)
    {
        printf(RED);
        printf("usage : %s nb1 nb2 nb3 (trois entiers)\n", argv[0]);
        printf(WHITE);
        exit(EXIT_FAILURE);
    }

    // Création thread supplémentaire 1
    int *nbAffTh1 = malloc(sizeof(int));
    printf("[log] malloc(%p)\n", nbAffTh1);
    *nbAffTh1 = atoi(argv[2]);
    returnValue = pthread_create(&thr1, NULL, affiche, (void *)nbAffTh1);
    if (returnValue != 0)
    {
        fprintf(stderr, "Erreur dans pthread_create\n");
        exit(EXIT_FAILURE);
    }

    // Création thread supplémentaire 2
    int *nbAffTh2 = malloc(sizeof(int));
    printf("[log] malloc(%p)\n", nbAffTh2);
    *nbAffTh2 = atoi(argv[3]);
    returnValue = pthread_create(&thr2, NULL, affiche, (void *)nbAffTh2);
    if (returnValue != 0)
    {
        fprintf(stderr, "Erreur dans pthread_create\n");
        exit(EXIT_FAILURE);
    }

    // Affichages par thread principal
    for (i = 1; i <= atoi(argv[1]); i++)
    {
        printf(BLUE);
        printf("Thread principal : Affichage %d/%d\n", i, atoi(argv[1]));
        printf(WHITE);
        sleep(1);
    }
    printf("[log] Fin des %d affichages du th. principal \n", atoi(argv[1]));
    pthread_exit(EXIT_SUCCESS);
}

void *affiche(void *nbAffPointGen)
{
    int *nbAff = (int *)nbAffPointGen;
    int i;
    for (i = 1; i <= *nbAff; i++)
    {
        printf(CYAN);
        printf("Affichage %d/%d\n", i, *nbAff);
        printf(WHITE);
        sleep(1);
    }
    printf("[log] Fin des %d affichages, free(%p)\n", *nbAff, nbAffPointGen);
    free(nbAffPointGen);
    pthread_exit(EXIT_SUCCESS);
}
