/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** my_strcmp
*/

#include "my.h"

char *my_strcat(char *first, char *two)
{
    int len = (my_strlen(first) + my_strlen(two) + 1);
    char *final = malloc(sizeof(char) * len);
    int i = 0;
    for (int e = 0; first[e] != '\0'; e++) {
        final[i] = first[e];
        i++;
    }
    for (int z = 0; two[z] != '\0'; z++) {
        final[i] = two[z];
        i++;
    }
    final[i] = '\0';
    return final;
}
