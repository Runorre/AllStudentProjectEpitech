/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** main
*/

#include "my.h"

void help(char *str)
{
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
        my_printf("USAGE\n     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n     ");
        my_printf("map file representing the warehouse map,");
        my_printf("containing ‘#’ for walls,\n");
        my_printf("     ‘P’ for the player, ‘X’ for boxes ");
        my_printf("and ‘O’ for storage locations.\n");
        exit(0);
    }
}

void show(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw("%s\n", map[i]);
    }
}

int game(struct data *jeu)
{
    int key = 0, finish = 0;
    while (1) {
        clear();
        checksize(jeu->map);
        show(jeu->map);
        finish = ifvictory(&(*jeu));
        if (finish == 1) {
            return 0;
        }
        finish = iflose(&(*jeu));
        if (finish == 2) {
            return 1;
        }
        key = getch();
        keyevent(key, &(*jeu));
        printo(&(*jeu));
        refresh();
    }
}

void reset(struct data *jeu)
{
    char *path = jeu->path;
    struct data jeu2 = create_data(path);
    game(&jeu2);
}

int main(int ar, char **av)
{
    int end = 0;
    if (ar != 2)
        return 84;
    help(av[1]);
    struct data jeu = create_data(av[1]);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    end = game(&jeu);
    clear();
    show(jeu.map);
    refresh();
    endwin();
    return end;
}
