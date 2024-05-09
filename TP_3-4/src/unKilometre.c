#include <std.h>
#include <prog_sys.h>
#include <colors.h>

int main()
{
    printf(WHITE);
    for (int i = 1; i <= 30; i++)
    {
        printf(("(%d) %d km à pied, ça use, ça use. %d km à pied, ça use les souliers. \n"), getpid(), i, i);
        sleep(1);
    }
    execlp("./bin/unProgrammeQuiNExistePas", "unProgrammeQuiNExistePas", (char *)NULL);
    perror(RED);
    perror("Erreur : le programme qui n'existe pas n'existe pas! \n");
    execlp("./bin/unKilometre", "unKilometre", (char *)NULL);
    perror(RED);
    perror("Erreur : le recouvrement de code a échouer! \n");
    return (EXIT_SUCCESS);
}