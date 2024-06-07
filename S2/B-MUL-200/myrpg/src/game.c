/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** game
*/

#include "rpg.h"

void events_game(sys_data* sys, champ_s** mc, tile_s* collisions, map_s *map)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            break;
        case sfEvtKeyPressed:
            if (sys->event.key.code == sfKeyI) inventaire(sys, *mc);
            move_player(sys->event.key.code, mc, collisions);
            sfView_setCenter(sys->view, sfSprite_getPosition(((*mc)->sprite)));
            sfRenderWindow_setView(sys->window, sys->view);
            if (sys->event.key.code == sfKeyEscape) {
                sfView_reset(sys->view, sys->rect_view);
                pause_game(sys, *mc);
            } break;
        default:
            break;
    }
}

int game(sys_data* sys, map_s* map, champ_s* mc)
{
    mc->map = map->id; map->boss = init_boss(map->id);
    while (sfRenderWindow_isOpen(sys->window)) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            events_game(sys, &mc, map->mid, map);
        }
        set_view(sys, mc->sprite);
        sfRenderWindow_clear(sys->window, sfBlack);
        draw_map(sys->window, map, mc);
        draw_tp(sys->window, map->tp);
        tp_map(map->tp, mc, sys);
        fight_a_boss(&mc, &map, sys);
        sfRenderWindow_display(sys->window);
        if (mc->q1 == 1 && mc->q2 == 1 && mc->q3 == 1) {
            sfView_reset(sys->view, sys->rect_view);
            sfRenderWindow_setView(sys->window, sys->view);
            place_credit(sys);
        }
    }
    return 0;
}
