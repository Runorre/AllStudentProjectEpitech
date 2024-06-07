/*
** EPITECH PROJECT, 2023
** generator
** File description:
** initlab
*/

#include "my.h"

char **createstruct(int x, int y)
{
    char **laby = malloc(sizeof(char *) * (x + 1));
    for (int i = 0; i != x; i++) {
        laby[i] = malloc(sizeof(char) * (y + 1));
        for (int j = 0; j != y; j++)
            laby[i][j] = 'X';
        laby[i][y] = '\0';
    }
    laby[x] = NULL;
    return laby;
}
