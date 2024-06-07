/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** my_str_to_word_array_adam
*/
#include "../include/lem_in.h"

int count_until_limit(char* str, char limit, int i)
{
    int n = 0;
    while (str[i] != '\0' && str[i] != limit) {
        i ++;
        n ++;
    }
    return n;
}

int count_occurences(char* str, char c)
{
    int i = 0, n = 0;
    while (str[i] != '\0') {
        n += (str[i] == c) ? 1 : 0;
        i ++;
    }
    return n;
}

void adapt_tab_for_vincent(char** tab)
{
    int i = 0, j;
    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            tab[i][j] = (tab[i][j] == '#' && tab[i][j + 1] != '#'
            && tab[i][j - 1] != '#') ? '\0' : tab[i][j];
            j ++;
        }
        i ++;
    }
}

char** my_str_to_word_array_adam(char* str, char limit)
{
    int i = 0, k = 0, j;
    char** tab = malloc(sizeof(char) * count_occurences(str, limit) + 2);
    while (str[i] != '\0') {
        j = 0;
        tab[k] = malloc(sizeof(char) * count_until_limit(str, limit, i) + 1);
        while (str[i] != limit && str[i] != '\0') {
            tab[k][j] = str[i];
            i ++, j ++;
        }
        tab[k][i] = '\0';
        if (str[i] != '\0')
            i ++;
        k ++;
    }
    tab[k] = NULL;
    return tab;
}
