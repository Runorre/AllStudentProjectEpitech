/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** error
*/

#include "my.h"

void checksize(char **map)
{
    int x = 0, y = 0, len_x = 0, len_y = 0;
    len_y--;
    getmaxyx(stdscr, y, x);
    for (int i = 0; map[i] != NULL; i++) {
        if (len_x < my_strlen(map[i]))
            len_x = my_strlen(map[i]);
        len_y++;
    }
    len_y++;
    if (y < len_y || x < len_x) {
        getmaxyx(stdscr, y, x);
        while (y < len_y || x < len_x) {
            getmaxyx(stdscr, y, x);
            clear();
            mvprintw(y / 2, x / 3, "Please resize a screen");
            refresh();
        }
        clear();
    }
}

char **deleteendline(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (my_strlen(map[i]) == 0) {
            map[i] = NULL;
            return map;
        }
    }
    return map;
}

int verif1(char **map)
{
    int i = 0, j = 0;
    while (map[i] != NULL) {
        if (map[i][j] != '#' && map[i][j] != 'O'
        && map[i][j] != 'X' && map[i][j] != ' '
        && map[i][j] != 'P' && map[i][j] != '\0') {
            exit(84);
        }
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    return i;
}

void verif2(int len, char **map)
{
    for (int i = 0; map[0][i] != '\0'; i++) {
        if (map[0][i] != '#')
            exit(84);
    }
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i][0] != '#')
            exit(84);
    }
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i][my_strlen(map[i]) - 1] != '#')
            exit(84);
    }
    for (int i = 0; map[len - 1][i] != '\0'; i++) {
        if (map[len - 1][i] != '#')
            exit(84);
    }
}

char **create_map_em(char const *path)
{
    char **map = getmap(path);
    map = deleteendline(map);
    int len = verif1(map);
    if (len <= 2)
        exit(84);
    verif2(len, map);
    return map;
}
