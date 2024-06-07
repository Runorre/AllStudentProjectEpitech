/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** task02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *final = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);
    int n = 0;
    while (dest[n] != '\0') {
        final[n] = dest[n];
        n++;
    } int j = 0;
    while (src[j] != '\0') {
        final[n + j] = src[j];
        j++;
    }
    final[n + j] = '\0';
    return final;
}
