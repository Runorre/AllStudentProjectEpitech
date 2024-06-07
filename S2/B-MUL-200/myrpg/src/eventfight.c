/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** eventfight
*/

#include "rpg.h"

void action_mainmenu(fight_s *fight, sys_data *sys)
{
    if (fight->move_cursor == 0) {
        fight->down_status = 1;
        fight->clock = sfClock_create();
        attack_enemy(fight, sys);
    }
    if (fight->move_cursor == 1) {
        fight->move_cursor = 0;
        pos_spell(fight, sys);
        sfSprite_setPosition(fight->cursor,
        (sfVector2f) {fight->s.x - 600.0, fight->s.y + 260.0});
        fight->down_status = 4;
        fight->changemenu = 1;
        fight->clock = sfClock_create();
    }
    if (fight->move_cursor == 2)
        sys->fight = 0;
}

void move_cursor(fight_s *fight, sys_data *sys, sfKeyCode key)
{
    switch (key) {
        case sfKeyLeft: case sfKeyQ:
            sfSound_play(fight->cur_s);
            move_l_cursor(fight, sys);
            break;
        case sfKeyRight: case sfKeyD:
            sfSound_play(fight->cur_s);
            move_r_cursor(fight, sys);
            break;
        case sfKeyReturn:
            sfSound_play(fight->cur_s);
            action_mainmenu(fight, sys);
            break;
        default: break;
    }
}

void mage_move(fight_s *fight, sys_data *sys, sfKeyCode key)
{
    switch (key) {
        case sfKeyLeft: case sfKeyQ: case sfKeyDown: case sfKeyS:
            sfSound_play(fight->cur_s);
            move_l_cursor_m(fight, sys);
            break;
        case sfKeyRight: case sfKeyD: case sfKeyUp: case sfKeyZ:
            sfSound_play(fight->cur_s);
            move_r_cursor_m(fight, sys);
            break;
        case sfKeyReturn:
            sfSound_play(fight->cur_s);
            magic_attack(fight, sys);
            break;
        case sfKeyBack:
            sfSound_play(fight->cur_s);
            sfSprite_setPosition(fight->cursor,
            (sfVector2f) {fight->s.x - 530.0, fight->s.y + 300.0});
            fight->down_status = 0;
            fight->move_cursor = 0; break;
    }
}

void down_menu_event(fight_s *fight, sys_data *sys, sfKeyCode key)
{
    if (fight->down_status == 0)
        move_cursor(fight, sys, key);
    if (fight->down_status == 4 && fight->changemenu == 0)
        mage_move(fight, sys, key);
    if (fight->changemenu == 1 &&
    sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) >= 0.1) {
        fight->changemenu = 0;
        sfClock_destroy(fight->clock);
    }
}
