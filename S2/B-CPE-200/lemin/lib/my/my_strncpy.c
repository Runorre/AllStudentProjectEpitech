/*
** EPITECH PROJECT, 2023
** lib/my/my_strncpy
** File description:
** libC
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i++;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return (dest);
}
