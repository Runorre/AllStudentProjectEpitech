/*
** EPITECH PROJECT, 2023
** 5_duo
** File description:
** check_win
*/

#include "my.h"

int i_love_c_one(game *game_s, char to_check, int i)
{
    int win = -1;
    for (int j = 0; j < game_s->size; j++)
        if (game_s->area[i][j] != to_check)
            win = 0;
    return win;
}

int i_love_c_one_bis(game *game_s, char to_check, int i)
{
    int win = -1;
    for (int j = 0; j < game_s->size; j++)
        if (game_s->area[j][i] != to_check)
            win = 0;
    return win;
}

int check_vertical(game *game_s, char to_check)
{
    for (int i = 0, win = -1; i < game_s->size; i++, win = -1) {
        win = i_love_c_one(game_s, to_check, i);
        if (win == -1)
            return 1;
    }
    return 0;
}

int check_horizontal(game *game_s, char to_check)
{
    for (int i = 0, win = -1; i < game_s->size; i++, win = -1) {
        win = i_love_c_one_bis(game_s, to_check, i);
        if (win == -1)
            return 1;
    }
    return 0;
}

int check_diagonal(game *game_s, char to_check)
{
    int win = -1;
    for (int i = 0; i < game_s->size; i++)
        if (game_s->area[i][i] != to_check)
            win = 0;
    if (win == -1)
        return 1;
    win = -1;
    for (int i = 0, j = game_s->size - 1; i < game_s->size; i++, j--)
        if (game_s->area[i][j] != to_check)
            win = 0;
    if (win == -1)
        return 1;
    return 0;
}
