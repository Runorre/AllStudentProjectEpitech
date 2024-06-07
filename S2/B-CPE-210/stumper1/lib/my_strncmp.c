/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** fzfzefzefefdddd
*/

#include "../include/my.h"

int my_strncmp(char *s1, char *s2, int nbr)
{
    int x = 0;
    while (s1[x] != '\0' && s2[x] != '\0' && x < nbr) {
        if (s1[x] != s2[x])
            return (s1 - s2);
        x++;
    }
    return (0);
}
