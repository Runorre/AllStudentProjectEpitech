/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** victory
*/

#include "my.h"

void printo(struct data *jeu)
{
    int x, y;
    for (int i = 0; i != jeu->nbr_o; i++) {
        y = jeu->co_o[i][0];
        x = jeu->co_o[i][1];
        if (jeu->map[y][x] == ' ')
            jeu->map[y][x] = 'O';
    }
}

int ifvictory(struct data *jeu)
{
    int x, y, vic = jeu->nbr_o;
    for (int i = 0; i != jeu->nbr_o; i++) {
        y = jeu->co_o[i][0];
        x = jeu->co_o[i][1];
        if (jeu->map[y][x] != 'X')
            vic--;
    }
    if (vic == jeu->nbr_o){
        show(jeu->map);
        return 1;
    }
    return 0;
}
