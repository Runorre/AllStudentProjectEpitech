/*
** EPITECH PROJECT, 2023
** Cesar
** File description:
** main
*/

#include "my.h"

int main(int ac, char **ar)
{
    if (ac != 4)
        return 84;
    if (checknbr(ar[3]) == 0)
        return 84;
    if (my_strcmp("-f", ar[1]) == 0 &&
        my_strcmp("-s", ar[1]) == 0)
        return 84;
    return init_cesar(ac, ar);
}
