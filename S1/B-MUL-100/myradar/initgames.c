/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** init2
*/
#include "my.h"

void set_rotation(plane *p)
{
    float a = p->end.x - p->pos.x;
    float o = p->end.y - p->pos.y;
    float rota = atan2f(o, a) * (180.0 / PI);
    sfSprite_setRotation(p->sp, rota);
    sfRectangleShape_setRotation(p->hitbox, rota);
}
