#include "../../include/std.h"
#include "../../include/prog_sys.h"
#include "../../include/colors.h"

int main()
{
    pid_t pid_fils = -1;

    int tube[2];
    pipe(tube);
    char buffer;

    pid_fils = fork();

    if (pid_fils != 0)
    {
        /* Code du père */
        // sleep(10);
        close(tube[0]);
        char *text = "Lorem ipsum dolor sit amet consectetur adipisicing elit.";
        printf(BLUE);
        printf("<père> Écriture en cours");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".\n");
        sleep(1);
        printf(WHITE);
        write(tube[1], text, strlen(text));
        close(tube[1]);
        wait(NULL);
    }
    else
    {
        /* Code du fils */
        close(tube[1]);
        while (read(tube[0], &buffer, 1) > 0)
        {
            sleep(1);
            printf(CYAN);
            printf("<fils> Caractère lu : %c\n", buffer);
            printf(WHITE);
        }
        close(tube[0]);
        exit(EXIT_SUCCESS);
    }
}