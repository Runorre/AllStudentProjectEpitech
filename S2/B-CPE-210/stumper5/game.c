/*
** EPITECH PROJECT, 2023
** 5_duo
** File description:
** game
*/

#include "my.h"

int i_love_c_one_bis_bis(game *game_s, int i)
{
    for (int j = 0; j < game_s->size; j++)
        if (game_s->area[i][j] == ' ')
            return 0;
    return 1;
}

int check_draw(game *game_s)
{
    int r_value = 1;
    for (int i = 0; i < game_s->size && r_value == 1; i++)
        r_value = i_love_c_one_bis_bis(game_s, i);
    return r_value;
}

void exit_print(char *to_print, int to_exit, game *game_s)
{
    printf("%s\n", to_print);
    order66(game_s);
    exit(to_exit);
}

void game_loop(game *game_s)
{
    for (int win = 0; win != 1; ) {
        win += check_win_p1(game_s);
        win += check_win_p2(game_s);
        print_array(game_s->area, game_s);
        if (win == 1 || win == 3)
            exit_print("Player 1 won!", 0, game_s);
        if (win == 2)
            exit_print("Player 2 won!", 0, game_s);
        if (check_draw(game_s) == 1)
            exit_print("Draw!", 0, game_s);
        for (int good = 0; good != 1; )
            good = action_player(game_s);
        place_game(game_s, game_s->pos_x, game_s->pos_y);
        game_s->turn_player = !game_s->turn_player;
    }
}
