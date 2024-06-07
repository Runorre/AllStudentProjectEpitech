/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell2-angelo.anselmet
** File description:
** order66
*/

#include "my.h"

void order66(char **str)
{
    if (str == NULL) {
        free(str);
        return;
    }
    for (int i = 0; str[i]; i++) {
        free(str[i]);
    }
    free(str);
    return;
}
