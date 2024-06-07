/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** csm
*/

#include "my.h"

void mousecsm(struct system_data *s, sfSprite *sp)
{
    s->mouse = sfMouse_getPosition((const sfWindow *) s->window);
    sfSprite_setPosition(sp, (sfVector2f) {s->mouse.x - 33, s->mouse.y - 26});
}
