/*
** EPITECH PROJECT, 2023
** lib/my/my_strcpy
** File description:
** libC
*/
#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    char *result = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return (result);
}
