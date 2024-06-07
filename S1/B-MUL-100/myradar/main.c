/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** main
*/

#include "my.h"

int helper(void)
{
    my_printf("Air traffic simulation panel\n\n");
    my_printf("USAGE\n");
    my_printf("     ./my_radar [OPTIONS] path_to_script\n");
    my_printf("     path_to_script The path to the script file.\n\n");
    my_printf("OPTIONS\n");
    my_printf("     -h     print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("     'L' key     enable/disable hitboxes and areas.\n");
    my_printf("     'S' key     enable/disable sprites.\n");
    return 0;
}

int whereobj(char *str, ll_tower **alltower, ll_plane **allplane)
{
    if (str[0] == 'T')
        return create_tower(str, alltower);
    if (str[0] == 'A')
        return create_plane(str, allplane);
    return 84;
}

int checkingfile(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *doc = NULL;
    size_t len = 0;
    int checker = 1, zzz = 1;
    ll_tower *alltower = NULL;
    ll_plane *allplane = NULL;
    if (fd == NULL) {
        my_printf("./my_radar: bad arguments\n");
        return 84;
    }
    if (getline(&doc, &len, fd) == -1) {
        my_printf("./my_radar: bad file\n");
        return 84;
    }
    while (checker != -1) {
        if (whereobj(doc, &alltower, &allplane) == 84)
            return 84;
        checker = getline(&doc, &len, fd);
    }
    return init_radar(allplane, alltower);
}

int main(int ac, char **ar)
{
    if (ac != 2)
        return 84;
    if (ac == 2 && ar[1][0] == '-' && ar[1][1] == 'h' && ar[1][2] == '\0')
        return helper();
    return checkingfile(ar[1]);
}
