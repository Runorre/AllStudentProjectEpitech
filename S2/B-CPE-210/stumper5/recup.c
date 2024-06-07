/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-stumper5-angelo.anselmet
** File description:
** recup
*/

#include "my.h"

int getarg(game *ff, char *str)
{
    int virgule = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',' && virgule != 0)
            return 0;
        if (str[i] == ',' && virgule == 0)
            virgule = i;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != '\n')
                return 0;
    }
    if (virgule == 0)
        return 0;
    ff->pos_x = atoi(str);
    ff->pos_y = atoi(&str[virgule + 1]);
    if (ff->pos_x >= ff->size || ff->pos_y >= ff->size ||
    ff->area[ff->pos_y][ff->pos_x] != ' ' || str[virgule + 1] == '\n')
        return 0;
    return 1;
}

int action_player(game *ujk)
{
    char *str = NULL;
    size_t len = 0;
    if (ujk->turn_player)
        printf("Player 2> ");
    else
        printf("Player 1> ");
    if (getline(&str, &len, stdin) == -1) {
        free(str);
        order66(ujk);
        exit(0);
    }
    int hello = getarg(ujk, str);
    free(str);
    return hello;
}
