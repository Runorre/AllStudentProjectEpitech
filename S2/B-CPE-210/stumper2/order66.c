/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** order66
*/

#include "my.h"

void order66(char **str)
{
    int j = 0;
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
        j = i;
    }
    free(str[j + 1]);
    free(str);
}

