/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int	i = 0;

    while ((s1[i] == s2[i]) && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
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
