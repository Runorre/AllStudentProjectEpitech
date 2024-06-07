/*
** EPITECH PROJECT, 2022
** converter.c
** File description:
** convertir long
*/

#include <stdlib.h>
#include "my.h"

char *exa_long(unsigned long int nb, int base, int maj)
{
    int i = 0, cos = 0, addletters = majletters(maj);;
    char *carac;
    char *str = malloc(sizeof(char) * 100000);
    str[i] = 0;
    while (nb > 0) {
        if (nb % base == 0) {
            str[i] = '0';
        }
        if (nb >= 16 && nb % base != 0) {
            carac = exa(nb % 16, base, maj);
            str[i] = carac[0];
        } if (nb > 9 && nb < 16) {
            cos = nb % base;
            str[i] = cos + addletters;
        } if (nb <= 9 && nb >= 0) {
            str[i] = nb % base + 48;
        }
        nb = nb / base; i++;
    }
    return str;
}

char *converter_long(unsigned long nb, int base, int maj)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100000);
    if (base == 10) {
        my_putnbr(nb);
    }
    if (base == 16) {
        return my_revstr(exa_long(nb, base, maj));
    }
    while (nb > 0) {
        str[i] = nb % base + '0';
        nb = nb / base;
        i++;
    }
    my_revstr(str);
    return str;
}
