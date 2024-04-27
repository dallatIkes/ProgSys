#include <std.h>
#include <prog_sys.h>
#include <colors.h>

int main()
{
    pid_t pid_fils = -1;
    int tube[2];
    pipe(tube);

    pid_fils = fork();

    if (pid_fils != 0)
    {
        /*Code du père*/
        close(tube[0]);
        int nb;
        printf(BLUE);
        printf("<Père> Veuillez entrer un nombre : ");
        printf(WHITE);
        scanf("%d", &nb);
        write(tube[1], &nb, (int)sizeof(int));
        close(tube[1]);
        wait(NULL);
    }
    else
    {
        /*Code du fils */
        int nb;
        read(tube[0], &nb, (int)sizeof(int));
        printf(CYAN);
        printf("<Fils> Le résultat est : %d\n", nb * nb);
        printf(WHITE);
        close(tube[0]);
        exit(EXIT_SUCCESS);
    }
}