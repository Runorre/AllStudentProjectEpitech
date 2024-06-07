/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** lose
*/

#include "my.h"

int checkx(struct data *jeu, int i, int j)
{
    if (jeu->map[i - 1][j] == '#' || jeu->map[i + 1][j] == '#' ||
    jeu->map[i - 1][j] == 'X' || jeu->map[i + 1][j] == 'X') {
        if (jeu->map[i][j - 1] == '#' || jeu->map[i][j + 1] == '#' ||
        jeu->map[i][j - 1] == 'X' || jeu->map[i][j + 1] == 'X')
            return 1;
    }
    return 0;
}

int iflose(struct data *jeu)
{
    int i = 0, j = 0, los = 0;
    while (jeu->map[i] != NULL) {
        if (jeu->map[i][j] == 'X') {
            los += checkx(&(*jeu), i, j);
        }
        if (jeu->map[i][j] == '\0') {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    if (los == jeu->nbr_x) {
        show(jeu->map);
        return 2;
    }
    return 0;
}
