/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** my_strcmp
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0, len = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
