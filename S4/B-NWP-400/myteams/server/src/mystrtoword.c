/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

char **checkerblank(char **str)
{
    int mall = 0;
    int i = 0;
    int j = 0;
    char **checker = NULL;

    for (i = 0; str[i]; i++)
        if (str[i][0] != '\0')
            mall++;
    if (mall == 0)
        return str;
    checker = malloc(sizeof(char *) * (mall + 1));
    for (i = 0; str[i]; i++)
        if (str[i][0] != '\0') {
            checker[j] = str[i];
            j++;
        }
    checker[j] = NULL;
    free(str);
    return checker;
}

int verifymemory1(char const *str)
{
    int mem = 0;
    int i = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ':')
            mem++;
    mem++;
    return mem;
}

int verifymemory2(char const *str, int loc)
{
    int i = 0;

    while (str[loc] != ':' && str[loc] != '\r' &&
    str[loc] != '\n' && str[loc] != '\0') {
        loc++;
        i++;
    }
    return i;
}

char **sauver_le_soldat_cs(char **str, int e, int j)
{
    str[e][j] = '\0';
    str[e + 1] = NULL;
    return checkerblank(str);
}

char **my_str_to_word_array(char *str)
{
    int j = 0;
    int e = 0;
    int i = 0;
    char **final = NULL;

    final = malloc(sizeof(char **) * (verifymemory1(str) + 1));
    final[e] = malloc(sizeof(char) * (verifymemory2(str, 0) + 1));
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            final[e][j] = '\0';
            e++;
            final[e] = malloc(sizeof(char) * (verifymemory2(str, i + 1) + 1));
            j = 0;
        } else {
            final[e][j] = str[i];
            j++;
        }
    }
    return sauver_le_soldat_cs(final, e, j);
}
