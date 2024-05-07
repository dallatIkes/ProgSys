#include <colors.h>
#include <prog_sys.h>
#include <std.h>

void *routineThread(void *arg)
{
    long num = (long)arg;
    for (int i = 1; i <= 6; i++)
    {
        printf(CYAN);
        printf("Thread numero : %ld (%d/6) \n", num, i);
        printf(WHITE);
        sleep(1);
    }
    return (void *)EXIT_SUCCESS;
}

int main()
{
    pthread_t thr1, thr2, thr3;
    int returnValue = pthread_create(&thr1, NULL, routineThread, (void *)1);

    if (returnValue != 0)
    {
        fprintf(stderr, "Erreur pthread_create premier thread\n");
    }

    returnValue = pthread_create(&thr2, NULL, routineThread, (void *)2);

    if (returnValue != 0)
    {
        fprintf(stderr, "Erreur pthread_create deuxième thread\n");
    }

    returnValue = pthread_create(&thr3, NULL, routineThread, (void *)3);

    if (returnValue != 0)
    {
        fprintf(stderr, "Erreur pthread_create troisième thread\n");
    }

    for (int i = 1; i <= 4; i++)
    {
        printf(BLUE);
        printf("======================= \n");
        printf("Thread principal (%d/4) \n", i);
        printf("======================= \n");
        printf(WHITE);
        sleep(1);
    }

    pthread_exit(EXIT_SUCCESS);
}