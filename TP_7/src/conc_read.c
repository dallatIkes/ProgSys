#include <std.h>
#include <prog_sys.h>
#include <colors.h>

int main()
{
    pid_t pid_fils1 = -1;
    pid_t pid_fils2 = -1;

    int tube[2];
    pipe(tube);
    char buffer;

    pid_fils1 = fork();

    if (pid_fils1 != 0)
    {
        pid_fils2 = fork();

        if (pid_fils2 != 0)
        {
            /* Code du père */
            close(tube[0]);
            char *text = "Lorem ipsum dolor sit amet consectetur adipisicing elit.";
            printf(PURPLE);
            printf("<Père> Écriture en cours...\n");
            printf(WHITE);
            write(tube[1], text, strlen(text));
            close(tube[1]);
            wait(NULL);
        }
        else
        {
            /* Code du fils 2*/
            close(tube[1]);
            while (read(tube[0], &buffer, 1) > 0)
            {
                sleep(1);
                printf(CYAN);
                printf("<Fils2> Caractère lu : %c\n", buffer);
                printf(WHITE);
            }
            close(tube[0]);
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        /* Code du fils 1 */
        close(tube[1]);
        while (read(tube[0], &buffer, 1) > 0)
        {
            sleep(1);
            printf(BLUE);
            printf("<Fils1> Caractère lu : %c\n", buffer);
            printf(WHITE);
        }
        close(tube[0]);
        exit(EXIT_SUCCESS);
    }
}