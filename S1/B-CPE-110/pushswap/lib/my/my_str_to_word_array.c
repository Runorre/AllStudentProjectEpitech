/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int verifymemory1(char const *str)
{
    int mem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            mem++;
    }
    mem++;
    return mem;
}

int verifymemory2(char const *str, int loc)
{
    int i = 0;
    while (str[loc] != '\n' && str[loc] != '\0') {
        loc++;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int j = 0, e = 0;
    char **final = malloc(sizeof(char **) * (verifymemory1(str) + 1));
    final[e] = malloc(sizeof(char) * (verifymemory2(str, 0) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            final[e][j] = '\0';
            e++;
            final[e] = malloc(sizeof(char) * (verifymemory2(str, i + 1) + 1));
            j = 0;
        } else{
            final[e][j] = str[i];
            j++;
        }
    }
    final[e][j] = '\0';
    final[e + 1] = malloc(1);
    final[e + 1] = '\0';
    return final;
}
