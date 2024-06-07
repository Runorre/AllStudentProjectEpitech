/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

int my_strstartwith(char *start, char *str)
{
    if (my_strlen(str) < my_strlen(start))
        return 0;
    for (int i = 0; start[i] != '\0'; i++) {
        if (str[i] != start[i])
            return 0;
    }
    return 1;
}

int findinstrstr(char *find, char **str)
{
    int i = 0;
    while (str[i]) {
        if (my_strstartwith(find, str[i]))
            return i;
        i++;
    }
    return -1;
}
