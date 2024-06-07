/*
** EPITECH PROJECT, 2023
** 5_duo
** File description:
** array_related
*/

#include "my.h"

void print_array(char **array, game *game_s)
{
    printf("+");
    for (int i = 0; i < game_s->size; i++)
        printf("-");
    printf("+\n");
    for (int i = 0; i < game_s->size; i++)
        printf("|%s|\n", array[i]);
    printf("+");
    for (int i = 0; i < game_s->size; i++)
        printf("-");
    printf("+\n");
}

void create_empty_area(game *game_s)
{
    char **array = malloc(sizeof(char *) * (game_s->size + 1));
    for (int i = 0; i < game_s->size; i++) {
        array[i] = malloc(sizeof(char) * (game_s->size + 1));
        for (int j = 0; j < game_s->size; j++)
            array[i][j] = ' ';
        array[i][game_s->size] = '\0';
    }
    array[game_s->size] = NULL;
    game_s->area = array;
}

void place_game(game *game_s, int x, int y)
{
    if (game_s->turn_player == 0 && game_s->area[y][x] == ' ')
        game_s->area[y][x] = game_s->p1;
    if (game_s->turn_player == 1 && game_s->area[y][x] == ' ')
        game_s->area[y][x] = game_s->p2;
}

int check_win_p1(game *game_s)
{
    int win = 0;
    win = check_vertical(game_s, game_s->p1);
    if (win == 1)
        return 1;
    win = check_horizontal(game_s, game_s->p1);
    if (win == 1)
        return 1;
    win = check_diagonal(game_s, game_s->p1);
    if (win == 1)
        return 1;
    return 0;
}

int check_win_p2(game *game_s)
{
    int win = 0;
    win = check_vertical(game_s, game_s->p2);
    if (win == 1)
        return 2;
    win = check_horizontal(game_s, game_s->p2);
    if (win == 1)
        return 2;
    win = check_diagonal(game_s, game_s->p2);
    if (win == 1)
        return 2;
    return 0;
}
