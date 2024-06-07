/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** ozefjofjerof
*/

#include "../include/my.h"

int my_put_nbr(int nbr)
{
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr < 10) {
        my_putchar(nbr % 10 + '0');
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_putchar(nbr % 10 + '0');
    }
    return (0);
}
