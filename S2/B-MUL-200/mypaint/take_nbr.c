/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** put nbr
*/

#include "my.h"

char *take_nbr(int nb)
{
    char *result = malloc(sizeof(char) * 11), end;
    int i = 0;
    while (nb >= 10) {
        end = nb % 10;
        result[i] = end + '0';
        nb = nb / 10;
        i++;
    }
    end = nb + '0';
    result[i] = end;
    i++;
    result[i] = '\0';
    my_revstr(result);
    return (result);
}
