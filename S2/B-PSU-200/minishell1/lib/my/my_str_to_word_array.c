/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

char **checkerblank(char **str)
{
    int mall = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i][0] != '\0') {
            mall++;
        }
    }
    if (mall == 0)
        return str;
    char **checker = malloc(sizeof(char *) * (mall + 1));
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i][0] != '\0') {
            checker[j] = str[i];
            j++;
        }
    }
    checker[j] = NULL;
    free(str);
    return checker;
}

int verifymemory1(char const *str)
{
    int mem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
            mem++;
    }
    mem++;
    return mem;
}

int verifymemory2(char const *str, int loc)
{
    int i = 0;
    while ((str[loc] != '\n' || str[loc] != ' ' || str[loc] == '\t')
            && str[loc] != '\0') {
        loc++;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char *str)
{
    if (str[my_strlen(str) - 1] == '\n') {
        str[my_strlen(str) - 1] = '\0';
    }
    int j = 0, e = 0;
    char **final = malloc(sizeof(char **) * (verifymemory1(str) + 1));
    final[e] = malloc(sizeof(char) * (verifymemory2(str, 0) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t') {
            final[e][j] = '\0';
            e++;
            final[e] = malloc(sizeof(char) * (verifymemory2(str, i + 1) + 1));
            j = 0;
        } else {
            final[e][j] = str[i];
            j++;
        }
    }
    final[e][j] = '\0';
    final[e + 1] = NULL;
    return checkerblank(final);
}
