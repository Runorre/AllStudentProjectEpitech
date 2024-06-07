/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-stumper5-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

typedef struct game_s{
    int turn_player;
    char p1;
    char p2;
    int size;
    int pos_x;
    int pos_y;
    char **area;
}game;

void order66(game *gm);
game *check_nothing(game *new);
game *init_game(int ac, char **ar);

void print_array(char **array, game *game_s);
void create_empty_area(game *game_s);
void place_game(game *game_s, int x, int y);
int check_win_p1(game *game_s);
int check_win_p2(game *game_s);

int i_love_c_one(game *game_s, char to_check, int i);
int i_love_c_one_bis(game *game_s, char to_check, int i);
int check_vertical(game *game_s, char to_check);
int check_horizontal(game *game_s, char to_check);
int check_diagonal(game *game_s, char to_check);

int i_love_c_one_bis_bis(game *game_s, int i);
int check_draw(game *game_s);
void exit_print(char *to_print, int to_exit, game *game_s);
void game_loop(game *game_s);

int getarg(game *ff, char *str);
int action_player(game *ujk);

#endif
