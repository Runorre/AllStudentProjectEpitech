/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** move
*/

#include "my.h"

void key_up(struct data *d)
{
    int x = d->p_x;
    if (d->map[d->p_y - 1][x] == '#')
        return;
    if (d->map[d->p_y - 1][x] == 'X') {
        if (d->map[d->p_y - 2][x] == '#' || d->map[d->p_y - 2][x] == 'X')
            return;
        d->map[d->p_y - 2][x] = 'X';
    }
    d->map[d->p_y - 1][x] = 'P';
    d->map[d->p_y][x] = ' ';
    d->p_y--;
}

void key_down(struct data *d)
{
    int x = d->p_x;
    if (d->map[d->p_y + 1][x] == '#')
        return;
    if (d->map[d->p_y + 1][x] == 'X') {
        if (d->map[d->p_y + 2][x] == '#' || d->map[d->p_y + 2][x] == 'X')
            return;
        d->map[d->p_y + 2][x] = 'X';
    }
    d->map[d->p_y + 1][x] = 'P';
    d->map[d->p_y][x] = ' ';
    d->p_y++;
}

void key_right(struct data *d)
{
    int y = d->p_y;
    if (d->map[y][d->p_x + 1] == '#')
        return;
    if (d->map[y][d->p_x + 1] == 'X') {
        if (d->map[y][d->p_x + 2] == '#' || d->map[y][d->p_x + 2] == 'X')
            return;
        d->map[y][d->p_x + 2] = 'X';
    }
    d->map[y][d->p_x + 1] = 'P';
    d->map[y][d->p_x] = ' ';
    d->p_x++;
}

void key_left(struct data *d)
{
    int y = d->p_y;
    if (d->map[y][d->p_x - 1] == '#')
        return;
    if (d->map[y][d->p_x - 1] == 'X') {
        if (d->map[y][d->p_x - 2] == '#' || d->map[y][d->p_x - 2] == 'X')
            return;
        d->map[y][d->p_x - 2] = 'X';
    }
    d->map[y][d->p_x - 1] = 'P';
    d->map[y][d->p_x] = ' ';
    d->p_x--;
}

void keyevent(int key, struct data *d)
{
    switch (key){
    case KEY_UP:
        key_up(&(*d));
        break;
    case KEY_DOWN:
        key_down(&(*d));
        break;
    case KEY_RIGHT:
        key_right(&(*d));
        break;
    case KEY_LEFT:
        key_left(&(*d));
        break;
    case ' ':
        reset(&(*d));
        break;
    }
}
