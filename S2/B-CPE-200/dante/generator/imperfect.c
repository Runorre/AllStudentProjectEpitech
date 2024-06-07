/*
** EPITECH PROJECT, 2023
** generator
** File description:
** imperfect
*/

#include "my.h"

void imparfait(char **laby, int x, int y)
{
    int x_r = rand() % x;
    int y_r = rand() % y;
    while (laby[x_r][y_r] != 'X') {
        x_r = rand() % x;
        y_r = rand() % y;
    }
    laby[x_r][y_r] = '*';
}
