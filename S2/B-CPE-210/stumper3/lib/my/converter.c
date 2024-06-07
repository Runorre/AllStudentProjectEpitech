/*
** EPITECH PROJECT, 2022
** converter.c
** File description:
** convertir
*/

#include <stdlib.h>
#include "my.h"

char *checkhastag(char *tab, char *str, int maj)
{
    int hastag = 0, i = 0;
    while (hastag == 0 && tab[i] != '\0') {
        if (tab[i] == '#')
            hastag = 1;
        i++;
    }
    if (hastag == 1) {
        int len = my_strlen(str);
        if (maj == 1) {
            str[len] = 'X';
            str[len + 1] = '0';
        } else {
            str[len] = 'x';
            str[len + 1] = '0';
        }
    }
    return str;
}

int majletters(int maj)
{
    if (maj == 1)
        return 55;
    else
        return 87;
}

char *exa(unsigned int nb, int base, int maj)
{
    int i = 0, cos = 0, addletters = majletters(maj);
    char *carac, *str = malloc(sizeof(char) * 100000);
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

char *converter(unsigned int nb, int base, int maj, char *tab)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100000);
    if (base == 10) {
        my_putnbr(nb);
    }
    if (base == 16) {
        char *ex = exa(nb, base, maj);
        checkhastag(tab, ex, maj);
        return my_revstr(ex);
    }
    while (nb > 0) {
        str[i] = nb % base + '0';
        nb = nb / base;
        i++;
    }
    my_revstr(str);
    return str;
}

int converter_int(int nb, int base, int maj)
{
    int i = 0;
    if (nb < 0) {
        nb = nb * -1;
    }
    char *str = malloc(sizeof(char) * nb + 2);
    while (nb != 0) {
        str[i] = ((nb % base) + 48);
        nb = nb / base;
        i++;
    }
    my_revstr(str);
    my_putstr(str);
    return (my_strlen(str));
}
