#include <colors.h>
#include <std.h>
#include <prog_sys.h>

void usage()
{
    printf(RED);
    printf("Usage : ./bin/lss <option>\n");
    printf(WHITE);
    printf("Options : \n");
    printf("\t[1] execl \n");
    printf("\t[2] execv \n");
    printf("\t[3] execlp \n");
    printf("\t[4] execvp \n");
}

void displayChoice(char *choice)
{
    printf(PURPLE);
    printf("You chose to use : ");
    printf(YELLOW);
    printf("%s", choice);
    printf(WHITE);
    printf("\n\n");
}

void displayError()
{
    perror(RED);
    perror("Erreur : le recouvrement de code a échouer! \n");
    printf(WHITE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage();
    }
    else
    {
        pid_t pidFils = -1;

        pidFils = fork();

        if (pidFils == 0)
        {
            switch (atoi(argv[1]))
            {
            case 1:
                displayChoice("execl");
                execl("/usr/bin/ls", "ls", "-l", "-h");
                displayError();
                break;
            case 2:
                displayChoice("execv");
                char *arg_v[] = {"ls", "-l", "-h", (char *)NULL};
                execv("/usr/bin/ls", arg_v);
                displayError();
                break;
            case 3:
                displayChoice("execlp");
                execlp("ls", "ls", "-l", "-h");
                displayError();
                break;
            case 4:
                displayChoice("execvp");
                char *arg_vp[] = {"ls", "-l", "-h", (char *)NULL};
                execvp("ls", arg_vp);
                displayError();
                break;
            default:
                usage();
                break;
            }
        }

        wait(NULL);
    }
}