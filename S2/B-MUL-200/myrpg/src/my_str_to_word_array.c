/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** my_str_to_word_array
*/

#include "rpg.h"

int num_words(char* str)
{
    int i, n;
    i = n = 0;
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        && str[i + 1] != '\0')
            n ++;
        i ++;
    }
    return n + 1;
}

int word_len_in_str(char* str, int i)
{
    int n = 0;
    while (str[i] != ' ' && str[i] != '\t'
    && str[i] != '\n' && str[i] != '\0') {
        n ++, i ++;
    }
    return n;
}

int tab_len(char** tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        i ++;
    }
    return i;
}

char** my_str_to_word_array(char* str)
{
    char** tab = malloc(sizeof(char*) * num_words(str) + 1);
    int i, j, k;
    i = k = 0;
    while (str[k] != '\0') {
        tab[i] = malloc(sizeof(char) * word_len_in_str(str, k) + 1);
        j = 0;
        while (str[k] != '\n'
        && str[k] != '\t' && str[k] != '\0') {
            tab[i][j] = str[k];
            k ++, j ++;
        }
        tab[i][j] = '\0';
        while (str[k] == '\t' || str[k] == '\n')
            k ++;
        i ++;
    }
    tab[i] = NULL;
    return tab;
}
