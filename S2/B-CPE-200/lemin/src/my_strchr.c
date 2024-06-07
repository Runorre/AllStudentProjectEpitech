/*
** EPITECH PROJECT, 2023
** src/my_strchr
** File description:
** Lem_in
*/
#include "../include/lem_in.h"

void remove_char(char *str, char c)
{
    int i, j;
    int len = my_strlen(str);
    for (i = j = 0; i < len; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char *) str;
        }
        str++;
    }
    return (NULL);
}
