/********************************
 * Fichier bancaire_multithread.c
 * Livre "Programmation d'applications système sous Linux"
 *
 * P. Alain, J. Chevelu, S. Le Maguer, V. Thion, B. Vozel
 *
 ********************************/
#include <colors.h>
#include <prog_sys.h>
#include <std.h>

void *virement(void *);       // Routine virement
void *calcul_somme(void *);   // Routine calcul somme
void *calcul_moyenne(void *); // Routine calcul val moy.

int cpt1, cpt2; // variables stockant le contenu des comptes
int somme;      // resultat de la somme des deux comtes
double moyenne; // resultat de la val moyenne des deux comptes

int main(int argc, char *argv[])
{
    pthread_t thr1, thr2, thr3;
    int valRetour;

    // Instanciation du contenu des comptes
    cpt1 = 200;
    fprintf(stdout, "Solde du compte 1  : %d\n", cpt1);
    cpt2 = 100;
    fprintf(stdout, "Solde du compte 2  : %d\n", cpt2);

    // Creation threads
    valRetour = pthread_create(&thr1, NULL, virement, (void *)1L);
    if (valRetour != 0)
    {
        perror("Erreur dans pthread_create thr1\n");
        exit(EXIT_FAILURE);
    }
    valRetour = pthread_create(&thr2, NULL, calcul_somme, (void *)2L);
    if (valRetour != 0)
    {
        perror("Erreur dans pthread_create thr2\n");
        exit(EXIT_FAILURE);
    }
    valRetour = pthread_create(&thr3, NULL, calcul_moyenne, (void *)3L);
    if (valRetour != 0)
    {
        perror("Erreur dans pthread_create thr2\n");
        exit(EXIT_FAILURE);
    }

    // Terminaison
    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);
    pthread_join(thr3, NULL);
    return EXIT_SUCCESS;
} // Fin main

void *virement(void *arg)
{
    fprintf(stdout, "(Thr %ld) Lancement thread virement \n", (long int)arg);
    fprintf(stdout, "(Thr %ld) Debit de 50 euros du cpt 1 \n", (long int)arg);
    cpt1 = 200 - 50;
    sleep(3); // Simulation d'un temps de réponse du SI bancaire
    cpt2 = 100 + 50;
    sleep(3); // Simulation d'un temps de réponse du SI bancaire
    fprintf(stdout, "(Thr %ld) Credit de 50 euros sur le cpt 2 \n", (long int)arg);
    fprintf(stdout, "(Thr %ld) Fin du virement \n", (long int)arg);
    pthread_exit(EXIT_SUCCESS);
}

void *calcul_somme(void *arg)
{
    fprintf(stdout, "(Thr %ld) Lancement thread calcul de la somme \n", (long int)arg);
    // Calcul de la somme des deux comptes
    sleep(1); // Simulation du temps de lancement du fils
    somme = cpt1 + cpt2;
    sleep(2); // Calcul de somme des cpts
    fprintf(stdout, "(Thr %ld) La somme des comptes est : %d\n", (long int)arg, somme);
    fprintf(stdout, "(Thr %ld) Fin du calcul de la somme \n", (long int)arg);
    pthread_exit(EXIT_SUCCESS);
}

void *calcul_moyenne(void *arg)
{
    fprintf(stdout, "(Thr %ld) Lancement thread calcul de la moyenne \n", (long int)arg);
    // Calcul de la somme des deux comptes
    sleep(1); // Simulation du temps de lancement du fils
    moyenne = (cpt1 + cpt2) / 2.0;
    sleep(2); // Calcul de moyenne des cpts
    fprintf(stdout, "(Thr %ld) La moyenne des comptes est : %f\n", (long int)arg, moyenne);
    fprintf(stdout, "(Thr %ld) Fin du calcul de la moyenne \n", (long int)arg);
    pthread_exit(EXIT_SUCCESS);
}
