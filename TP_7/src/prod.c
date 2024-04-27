#include <std.h>
#include <prog_sys.h>
#include <colors.h>

int main()
{
    mkfifo("pipe", 0600);
    int tube = open("pipe", O_WRONLY);
    char *text1 = "Lorem ipsum dolor sit amet consectetur adipisicing elit.";
    char *text2 = "Maxime mollitia,molestiae quas vel sint commodi repudiandae consequuntur voluptatum laborum numquam blanditiis harum quisquam eius sed odit fugiat iusto fuga praesentiumoptio, eaque rerum !";
    printf(BLUE);
    printf("<Producteur> Écriture dans le tube... \n");
    printf(WHITE);
    write(tube, text1, strlen(text1));
    sleep(5);
    write(tube, text2, strlen(text2));
    close(tube);
    unlink("pipe");
}