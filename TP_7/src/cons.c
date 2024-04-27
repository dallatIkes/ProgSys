#include <std.h>
#include <prog_sys.h>
#include <colors.h>

int main()
{
    int tube = open("pipe", O_RDONLY);
    char buffer;
    while (read(tube, &buffer, 1))
    {
        printf(CYAN);
        printf("<Consommateur> Lecture de : %c\n", buffer);
        printf(WHITE);
        sleep(1);
    }
    close(tube);
}