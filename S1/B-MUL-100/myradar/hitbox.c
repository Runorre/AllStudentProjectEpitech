/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** hitbox
*/

#include "my.h"

void checktowerplane2(ll_tower *tmp, ll_plane *allplane)
{
    for (ll_plane *tmp2 = allplane; tmp2; tmp2 = tmp2->next) {
        if ((tmp2->obj->pos.x >= ((tmp->obj->pos.x -
            (1080.0 * ((float) tmp->obj->rad / 100.0)))) &&
            tmp2->obj->pos.x <= ((tmp->obj->pos.x +
            (1080.0 * ((float) tmp->obj->rad / 100.0))))) &&
            tmp2->obj->pos.y >= ((tmp->obj->pos.y -
            (1080.0 * ((float) tmp->obj->rad / 100.0)))) &&
            tmp2->obj->pos.y <= (tmp->obj->pos.y +
            ((1080.0 * ((float) tmp->obj->rad / 100.0)))))
                tmp2->obj->safe = 1;
            else
            tmp2->obj->safe = 0;
    }
}

void checktowerplane1(ll_plane *allplane, ll_tower *alltower)
{
    for (ll_tower *tmp = alltower; tmp; tmp = tmp->next) {
        checktowerplane2(tmp, allplane);
    }
}

void checkwhitallplane(ll_plane *tmp)
{
    for (ll_plane *tmp2 = tmp->next; tmp2; tmp2 = tmp2->next) {
        if (tmp2->obj->show == 1 && tmp2->obj->safe == 0 &&
            (tmp->obj->pos.x >= tmp2->obj->pos.x - 17.0 &&
            tmp->obj->pos.x <= tmp2->obj->pos.x + 17.0) &&
            (tmp->obj->pos.y >= tmp2->obj->pos.y - 17.0 &&
            tmp->obj->pos.y <= tmp2->obj->pos.y + 17.0)) {
                tmp->obj->show = 0;
                tmp2->obj->show = 0;
            }
    }
}

void checkcollision_ptp(ll_plane *allplane)
{
    for (ll_plane *tmp = allplane; tmp; tmp = tmp->next) {
        if (tmp->obj->show == 1)
            checkwhitallplane(tmp);
    }
}
