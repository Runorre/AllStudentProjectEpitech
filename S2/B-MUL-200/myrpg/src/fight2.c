/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** fight2
*/

#include "rpg.h"

void fight_a_boss(champ_s** mc, map_s** map, sys_data* sys)
{
    int v = 1;
    sfVector2f size_mc = {32.0, 32.0};
    if ((*map)->boss == NULL) return;
    sfVector2f size_b = {200, 100};
    sfVector2f postmp = sfSprite_getPosition((*map)->boss->sprite);
    if (sprite_collisions((*mc)->sprite, size_mc, (*map)->boss->sprite,
        size_b)) {
        if (sys->event.key.code == sfKeyF) {
            v = init_fight(*mc, (*map)->boss, sys, *map);
            (*map)->boss = (v == 1) ? NULL : (*map)->boss;
            (*mc)->q1 = ((*map)->id == 2 && v == 1) ? 1 : (*mc)->q1;
            (*mc)->q2 = ((*map)->id == 3 && v == 1) ? 1 : (*mc)->q2;
            (*mc)->q3 = ((*map)->id == 5 && v == 1) ? 1 : (*mc)->q3;
            sfView_zoom(sys->view, 0.7);
        }
    }
    if (v != 1) {
        sfSprite_setPosition((*map)->boss->sprite, postmp);
        sfSprite_setScale((*map)->boss->sprite, (sfVector2f){1, 1});
    }
}

int draw_life(fight_s *fight, sys_data *sys)
{
    sfRenderWindow_drawSprite(sys->window, fight->s_box, NULL);
    sfRenderWindow_drawText(sys->window, fight->name, NULL);
    sfRenderWindow_drawText(sys->window, fight->hp, NULL);
    sfRenderWindow_drawText(sys->window, fight->mp, NULL);
}

void draw_upper2(fight_s *fight, sys_data *sys)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) > 2.5 &&
    fight->down_status == 3) {
        sys->fight = 4;
        sfClock_destroy(fight->clock);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) > 6.0 &&
    fight->down_status == 7) {
        sys->fight = 3;
        sfClock_destroy(fight->clock);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) > 2.5 &&
    fight->no_mana) {
        fight->no_mana = 0;
        sfClock_destroy(fight->clock);
    }
}

void draw_upper(fight_s *fight, sys_data *sys)
{
    sfRenderWindow_drawSprite(sys->window, fight->opt_box, NULL);
    sfRenderWindow_drawText(sys->window, fight->upper_msg, NULL);
    if (sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) > 1.5 &&
    fight->down_status == 1) {
        enemy_attack(fight, sys);
        fight->down_status = 2;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(fight->clock)) > 3.0 &&
    fight->down_status == 2) {
        fight->down_status = 0;
        sfSprite_setPosition(fight->cursor,
        (sfVector2f) {fight->s.x - 530.0, fight->s.y + 300.0});
        fight->move_cursor = 0;
        sfClock_destroy(fight->clock);
    }
    draw_upper2(fight, sys);
}
