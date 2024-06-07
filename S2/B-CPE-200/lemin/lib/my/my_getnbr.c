/*
** EPITECH PROJECT, 2022
** my_get_nbr.c
** File description:
** get_nbr
*/
#include <stdlib.h>

int my_getnbr(const char *str)
{
    int n = 0;
    int signe = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '-' && signe == -1 && n == 0) ||
            (str[i] == '+' && n == 0))
            signe = 1;
        if (str[i] == '-' && n == 0)
            signe = -1;
        if ((str[i] < '0' || str[i] > '9') && n > 0)
            break;
        if ((str[i] < '0' || str[i] > '9') && n == 0)
            continue;
        n += str[i] - 48;
        n *= 10;
    }
    n /= 10;
    return (n * signe);
}
