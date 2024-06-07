/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** cursor_f
*/

#include "rpg.h"

void move_r_cursor(fight_s *fight, sys_data *sys)
{
    sfVector2f offset = {0, 0};
    if (fight->move_cursor == 2) {
        fight->move_cursor = 0;
        offset.x = -800;
    } else {
        fight->move_cursor++;
        offset.x = 400;
    }
    sfSprite_move(fight->cursor, offset);
}

void move_l_cursor(fight_s *fight, sys_data *sys)
{
    sfVector2f offset = {0, 0};
    if (fight->move_cursor == 0) {
        fight->move_cursor = 2;
        offset.x = 800;
    } else {
        fight->move_cursor--;
        offset.x = -400;
    }
    sfSprite_move(fight->cursor, offset);
}

void move_l_cursor_m(fight_s *fight, sys_data *sys)
{
    sfVector2f offset = {0, 0};
    if (fight->move_cursor == 2 ||
    (fight->nbr_spells == 2 && fight->move_cursor == 1) ||
    (fight->nbr_spells == 1 && fight->move_cursor == 0)) {
        if (fight->nbr_spells == 3) {
            fight->move_cursor = 0;
            offset.y = -120;
        }
        if (fight->nbr_spells == 2) {
            fight->move_cursor = 0;
            offset.y = -60;
        }
        if (fight->nbr_spells == 1) {
            fight->move_cursor = 0;
            offset.y = 0;
        }
    } else {
        fight->move_cursor++;
        offset.y = 60;
    } sfSprite_move(fight->cursor, offset);
}

void move_r_cursor_m(fight_s *fight, sys_data *sys)
{
    sfVector2f offset = {0, 0};
    if (fight->move_cursor == 0) {
        if (fight->nbr_spells == 3) {
            fight->move_cursor = 2;
            offset.y = 120;
        }
        if (fight->nbr_spells == 2) {
            fight->move_cursor = 1;
            offset.y = 60;
        }
        if (fight->nbr_spells == 1) {
            fight->move_cursor = 0;
            offset.y = 0;
        }
    } else {
        fight->move_cursor--;
        offset.y = -60;
    }
    sfSprite_move(fight->cursor, offset);
}
