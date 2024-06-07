/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_word_array2
*/

#include <stdlib.h>

int verifymemory12(char const *str, char pars)
{
    int mem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == pars)
            mem++;
    }
    mem++;
    return mem;
}

int verifymemory22(char const *str, int loc, char pars)
{
    int i = 0;
    while ((str[loc] != pars)
            && str[loc] != '\0') {
        loc++;
        i++;
    }
    return i;
}

char **my_str_to_word_array2(char const *str, char pars)
{
    int j = 0, e = 0;
    char **final = malloc(sizeof(char **) * (verifymemory12(str, pars) + 1));
    final[e] = malloc(sizeof(char) * (verifymemory22(str, 0, pars) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == pars) {
            final[e][j] = '\0';
            e++;
            final[e] = malloc(sizeof(char) * (verifymemory22(str, i + 1, pars)
            + 1));
            j = 0;
        } else{
            final[e][j] = str[i];
            j++;
        }
    }
    final[e][j] = '\0';
    final[e + 1] = NULL;
    return final;
}
