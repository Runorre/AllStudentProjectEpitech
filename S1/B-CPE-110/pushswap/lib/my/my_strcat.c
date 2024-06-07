/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenates a two string
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char const *dest, char const *src)
{
    char *final = malloc(sizeof(char*) * (my_strlen(dest) + my_strlen(src)));
    int i = 0;
    for (int e = 0; dest[e] != '\0'; e++) {
        final[i] = dest[e];
        i++;
    }
    for (int e = 0; src[e] != '\0'; e++) {
        final[i] = src[e];
        i++;
    }
    return final;
}
