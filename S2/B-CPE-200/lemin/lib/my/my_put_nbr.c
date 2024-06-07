/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** put nbr
*/

#include "my.h"

int my_putnbr(int nb)
{
    char result[11], end;
    if (nb < 0) {
        my_putchar('-');
        my_put_unnbr(nb * -1);
    } else {
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
        my_putstr(result);
    }
}

int my_put_unnbr(unsigned int nb)
{
    char result[11], end;
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
    my_putstr(result);
}

int my_put_longnbr(long nb)
{
    char result[20], end;
    if (nb < 0) {
        my_putchar('-');
        my_put_longnbr(nb / -1);
    } else {
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
        my_putstr(result);
    }
}

int my_put_unlongnbr(unsigned long nb)
{
    char result[20], end;
    if (nb < 0) {
        my_putchar('-');
        my_put_longnbr(nb / -1);
    } else {
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
        my_putstr(result);
    }
}
