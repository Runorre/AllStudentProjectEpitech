/*
** EPITECH PROJECT, 2022
** space.c
** File description:
** space
*/

#include "my.h"
#include <stdlib.h>

int pos(int nb, char *tab)
{
    int i = 0;
    while (tab[i] != '\0') {
        if (tab[i] == '+' && nb > 0)
            my_putchar('+');
        i++;
    }
}

int verifneg(char *tab)
{
    int i = 0;
    while (tab[i] != '\0') {
        if (tab[i] == '-')
            return 1;
        i++;
    }
    return 0;
}

char if0(char *tab, int check)
{
    int i = 0;
    while (tab[i] != '\0' && check == 1) {
        if (tab[i] == '0' && (tab[i - 1] <= '0' || tab[i - 1] > '9'))
            return '0';
        i++;
    }
    return ' ';
}

int posspace(char *tab, int nbrlen, int check)
{
    int test = 0, i = 0, j = 0;
    char *nub = malloc(sizeof(char) * my_strlen(tab));;
    if (verifneg(tab) != 0)
        return 0;
    while (test == 0 && tab[i] != '\0') {
        while ((tab[i] >= '0' && tab[i] <= '9') &&
                (tab[i] != '0' || test == 1) && tab[i] != '\0') {
            nub[j] = tab[i];
            test = 1;
            i++;
            j++;
        }
        i++;
    }
    i = 0;
    if (my_strlen(nub) != 0)
        while (i <= my_getnbr(nub) - nbrlen) {
            my_putchar(if0(tab, check));
            i++;
        }
}

int negspace(char *tab, int nbrlen)
{
    int test = 0, i = 0, j = 0;
    char *nub = malloc(sizeof(char) * my_strlen(tab));;
    if (verifneg(tab) != 1)
        return 0;
    while (test == 0 && tab[i] != '\0') {
        while ((tab[i] >= '0' && tab[i] <= '9') &&
            (tab[i] != '0' || test == 1) && tab[i] != '\0') {
            nub[j] = tab[i];
            test = 1;
            i++;
            j++;
        }
        i++;
    }
    i = 0;
    if (my_strlen(nub) != 0)
        while (i <= my_getnbr(nub) - nbrlen) {
            my_putchar(' ');
            i++;
        }
}
