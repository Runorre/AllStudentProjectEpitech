/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *result;
    int len = my_strlen(src);
    len++;
    result = malloc(sizeof(char) * len);
    for (int i = 0; i != len; i++)
        result[i] = src[i];
    result[len] = '\0';
    return (result);
}
