/*
** EPITECH PROJECT, 2022
** my_putfloat
** File description:
** put float
*/

#include "my.h"

int my_putfloat(double nb, int dec)
{
    int nb_int = nb, i = dec, len = 0;
    nb = nb - nb_int;
    nb = nb * my_compute_power_rec(10, dec);
    i--;
    int virg = nb;
    my_put_nbr(nb_int);
    len = my_nbrlen(nb_int);
    if (dec != 0) {
        my_putchar('.');
        i = i - my_nbrlen(virg);
        while (i >= 0) {
        len++;
        my_putchar('0'); i--;
        }
        len++;
        my_put_nbr(virg); len += my_nbrlen(virg);
    }
    return len;
}

char my_putfloat_exa(double nb, int dec, int maj)
{
    int nb_int = nb, i = dec;
    nb = nb - nb_int;
    nb = nb * my_compute_power_rec(10, dec);
    i--;
    int virg = nb;
    my_putstr(converter(nb_int, 16, maj,""));
    if (dec != 0) {
    my_putchar('.');
    my_putstr(converter(virg, 16, maj,""));
    }
    i = i - my_nbrlen(virg);
    while (i >= 0) {
        my_putchar('0');
        i--;
    }
}

int put_i(int i, int len)
{
    if (i >= 0) {
        my_putstr("e+"); len++;
        if (i < 10) {
            my_putchar('0');
            len++;
        }
        my_put_nbr(i);
        len += my_nbrlen(i);
    }
    if (i < 0) {
        my_putstr("e-");
        len++;
        if (i > -10) {
            my_putchar('0');
            len++;
        }
        my_put_nbr(-i);
        len += my_nbrlen(-i);
    }
    return len;
}

int nota_scient(double nb, int dec)
{
    int i = 0, len = 0;
    while (nb >= 10) {
        i++;
        nb = nb / 10;
    }
    while (nb < 1) {
        i--;
        nb = nb * 10;
    }
    len += my_putfloat(nb, dec);
    len = put_i(i, len);
    return len;
}
