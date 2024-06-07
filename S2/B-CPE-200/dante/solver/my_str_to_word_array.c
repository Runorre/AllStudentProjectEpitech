/*
** EPITECH PROJECT, 2022
** my_str_to_word.c
** File description:
** task04
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"

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

char **my_str_to_word_array(char const *str)
{
    int len_str = my_strlen(str);
    int j = 0, i = 0, n = 0;
    char **tab = malloc(sizeof(char*) * len_str + 8);
    while (str[j] != '\0') {
        tab[i] = malloc (sizeof(char) * len_str + 1);
        n = 0;
        while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
            j ++;
        while (str[j] != ' ' && str[j] != '\n' &&
        str[j] != '\t' && str[j] != '\0') {
            tab[i][n] = str[j];
            n ++, j ++;
        } tab[i][n] = '\0';
        while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
            j ++;
        i ++;
    }
    tab[i] = NULL;
    return tab;
}
