/*
** EPITECH PROJECT, 2022
** my_str_to_word.c
** File description:
** task04
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int first_line(char const *str)
{
    int i = 0;
    while (str[i] != '\n')
        i++;
    return i + 1;
}

int error(char const *str, int nbr_line)
{
    int i = 0, j = 0;
    if (nbr_line < 2) {
        return -1;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n')
            j++;
        i++;
    }
    if (j - 1 != my_getnbr((char *)str))
        return -1;
}

int strline(char const *str)
{
    int i = 0, j = 0;
    while (str[i] != '\n')
        i++;
    while (str[i + 1] != '\n' && str[i + 1] != '\0') {
        i++;
        j++;
    }
    return j;
}

int boucle(char const *str, char **tab, int *i, int *j)
{
    int n = 0, nb = (*i), k = (*j);
    while (str[k] != ' ') {
        tab[nb][n] = str[k];
        k++;
        n++;
    }
    tab[nb][n] = '\0';
    return n;
}

char **my_str_to_word_array(char const *str)
{
    int len_str = my_strlen(str);
    int carac_line = strline(str);
    int j = 0, i = 0, n = 0;
    char **tab = malloc(sizeof(char*) * len_str + 1);
    while (j < len_str) {
        tab[i] = malloc (sizeof(char) * len_str + 1);
        n = boucle(str, tab, &i, &j);
        j = j + n;
        i++;
        j++;
    }
    return tab;
}
