/*
** EPITECH PROJECT, 2023
** cesar
** File description:
** checknbr
*/

#include "my.h"

int checknbr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+'
            || str[i] == '-')
            i++;
        else
            return 0;
    }
    return 1;
}
