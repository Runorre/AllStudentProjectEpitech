/*
** EPITECH PROJECT, 2023
** my_strtok
** File description:
** my_radar
*/
#include "../include/lem_in.h"

char *my_strtok(char *str, const char *delim)
{
    static char *p = NULL;
    if (str) p = str;
    else if (!p) return NULL;
    while (*p && contains(delim, *p)) p++;
    if (!*p) return NULL;
    char *start = p;
    while (*p && !contains(delim, *p)) p++;
    if (*p) *p++ = '\0';
    return start;
}

int contains(const char *str, char c)
{
    for (; *str; str++) {
        if (*str == c) return 1;
    }
    return 0;
}
