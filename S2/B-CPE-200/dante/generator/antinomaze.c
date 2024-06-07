/*
** EPITECH PROJECT, 2023
** generator
** File description:
** antinomaze
*/

#include "my.h"

int antimazeimp(char **laby, int x, int y)
{
    if (laby[x - 1][y - 1] == '*')
        return 0;
    laby[x - 1][y - 1] = '*';
    if (laby[x - 1][y - 2] == 'X' && laby[x - 2][y - 1] == 'X') {
        int decalage = 2;
        while (laby[x - 1][y - decalage] == 'X') {
            laby[x - 1][y - decalage] = '*';
            decalage++;
        }
    }
}
