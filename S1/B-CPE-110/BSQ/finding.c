/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** finding
*/

#include "my.h"

int placevalue(int **finder, int x, int y)
{
    int value = finder[y][x - 1];
    if (value > finder[y - 1][x])
        value = finder[y - 1][x];
    if (value > finder[y - 1][x - 1])
        value = finder[y - 1][x - 1];
    return value + 1;
}

char checking(int *value, char c)
{
    if (value[0] != 0)
        return 'x';
    else
        return c;
}

void show(int **square, int Ylimite, int Xlimite)
{
    for (int y = 0; y != Ylimite; y++) {
        for (int x = 0; x != Xlimite; x++) {
            my_printf("%i ", square[y][x]);
        }
        my_printf("\n");
    }
}

int *searchbigsquare(int **square, int y_limte, int x_limte)
{
    int *value = malloc(sizeof(int) * 3);
    value[0] = 0, value[1] = 0, value[2] = 0;
    int x = 1, y = 1;
    while (y != y_limte) {
        if (square[y][x] > value[0] && x != x_limte) {
            value[0] = square[y][x];
            value[1] = y;
            value[2] = x - 1;
        }
        if (x >= x_limte) {
            x = 0;
            y++;
        }
        x++;
    }
    return value;
}
