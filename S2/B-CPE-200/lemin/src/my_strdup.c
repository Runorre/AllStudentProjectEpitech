/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** task01
*/
#include "../include/lem_in.h"

char *my_strdup(char const *src)
{
    int i = 0, lenght = my_strlen(src);
    char *str = malloc(lenght + 1);
    for (i = 0; i <= lenght; i++) {
        str[i] = src[i];
    }
    return (str);
}
