/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** game
*/

#include "my.h"

void show_tower(ll_tower *alltower, sys_data *sys)
{
    for (ll_tower *tp = alltower; tp; tp = tp->next) {
        if ((sys->show_sp % 2) == 0)
            sfRenderWindow_drawSprite(sys->win, tp->obj->sp, NULL);
        if ((sys->show_hitbox % 2) == 0)
            sfRenderWindow_drawCircleShape(sys->win, tp->obj->cir, NULL);
    }
}

void show_plane(ll_plane *allplane, sys_data *sys)
{
    for (ll_plane *tmp = allplane; tmp; tmp = tmp->next) {
        if (tmp->obj->show == 1 && (sys->show_sp % 2) == 0)
            sfRenderWindow_drawSprite(sys->win, tmp->obj->sp, NULL);
        if (tmp->obj->show == 1 && (sys->show_hitbox % 2) == 0)
            sfRenderWindow_drawRectangleShape(sys->win, tmp->obj->hitbox, NULL);
    }
}

void move_plane(ll_plane *allplane, sys_data *sys)
{
    for (ll_plane *tmp = allplane; tmp; tmp = tmp->next) {
        sfClock_restart(sys->clock);
        sfSprite_move(tmp->obj->sp, tmp->obj->offset);
        sfRectangleShape_move(tmp->obj->hitbox, tmp->obj->offset);
        if ((tmp->obj->pos.x >= tmp->obj->end.x - 10.0 &&
            tmp->obj->pos.x <= tmp->obj->end.x + 10.0) &&
            (tmp->obj->pos.y >= tmp->obj->end.y - 10.0 &&
            tmp->obj->pos.y <= tmp->obj->end.y + 10.0)) {
                tmp->obj->show = 0;
            }
        tmp->obj->pos = sfRectangleShape_getPosition(tmp->obj->hitbox);
    }
}

void clock_plane(ll_plane *allplane, sys_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds >= 0.1) {
        move_plane(allplane, sys);
    }
}

void radar(ll_plane *allplane, ll_tower *alltower, sys_data *sys)
{
    sys->clock = sfClock_create();
    sys->show_hitbox = 0;
    sys->show_sp = 0;
    while (sfRenderWindow_isOpen(sys->win)) {
        loop_event(sys);
        sfRenderWindow_clear(sys->win, sfBlack);
        sfRenderWindow_drawSprite(sys->win, sys->bg, NULL);
        checktowerplane1(allplane, alltower);
        checkcollision_ptp(allplane);
        clock_plane(allplane, sys);
        show_tower(alltower, sys);
        show_plane(allplane, sys);
        sfRenderWindow_display(sys->win);
    }
}
