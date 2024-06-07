/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** checker
*/

#include "my.h"

void printnamefile(char *file)
{
    my_putstr("==> ");
    my_putstr(file);
    my_putstr(" <==\n");
}

int checkoptionheader(char *option, int check)
{
    for (int i = 0; option[i] != '\0'; i++) {
        if (option[i] == 'v')
            check = 1;
        if (option[i] == 'q')
            check = -42;
    }
    return check;
}

int checkoptioncorrect(int ac, char **ar)
{
    int i = 1;
    while (i != ac) {
        if (ar[i][0] == '-' && checkoption(ar[i]))
            return 1;
        i++;
    }
    return 0;
}

int checker(int ac, char **ar)
{
    int i = 1;
    int check = 0;
    while (i != ac) {
        if (ar[i][0] == '-')
            check = checkoptionheader(ar[i], check);
        if (ar[i][0] != '-' && check == 1)
            return 1;
        else if (ar[i][0] != '-')
            check++;
        i++;
    }
    return 0;
}
