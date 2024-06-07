/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-stumper5-angelo.anselmet
** File description:
** argu
*/

#include "my.h"

void check_argument2(int ac, char **ar, int i, game *new)
{
    if (strcmp("-s", ar[i]) == 0) {
        if (new->size != -1 || atoi(ar[i + 1]) <= 0) {
            order66(new);
            exit(84);
        }
        new->size = atoi(ar[i + 1]);
        return;
    } else {
        order66(new);
        exit(84);
    }
}

void check_argument(int ac, char **ar, int i, game *new)
{
    if ((strlen(ar[i]) != 3 || strlen(ar[i]) != 2) && ac - 1 == i) {
        order66(new);
        exit(84);
    }
    if (strcmp("-p1", ar[i]) == 0) {
        if (new->p1 != '\0' || strlen(ar[i + 1]) != 1) {
            order66(new);
            exit(84);
        }
        new->p1 = ar[i + 1][0];
        return;
    }
    if (strcmp("-p2", ar[i]) == 0) {
        if (new->p2 != '\0' || strlen(ar[i + 1]) != 1) {
            order66(new);
            exit(84);
        }
        new->p2 = ar[i + 1][0];
        return;
    } check_argument2(ac, ar, i, new);
}

game *check_nothing(game *new)
{
    if (new == NULL) {
        game *new = malloc(sizeof(game));
        new->p1 = 'X';
        new->p2 = 'O';
        new->size = 3;
        new->turn_player = 0;
        create_empty_area(new);
        return new;
    }
    if (new->p1 == '\0')
        new->p1 = 'X';
    if (new->p2 == '\0')
        new->p2 = 'O';
    if (new->p1 == new->p2) {
        order66(new);
        exit(84);
    }
    return new;
}

game *init_game(int ac, char **ar)
{
    game *new = malloc(sizeof(game));
    new->p1 = '\0', new->p2 = '\0', new->size = -1;
    new->turn_player = 0, new->area = NULL;
    int i = 1;
    while (ar[i]) {
        if (ar[i][0] == '-') {
            check_argument(ac, ar, i, new);
            i += 2;
        } else {
            order66(new);
            exit(84);
        }
    }
    if (new->size == -1)
        new->size = 3;
    create_empty_area(new);
    return check_nothing(new);
}
