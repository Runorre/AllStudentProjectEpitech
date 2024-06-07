/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** animationD
*/

#include "my.h"

void textanime(struct text *txt, struct system_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds > 0.4) {
        txt->color = sfColor_fromRGB(0,0,0);
        sfText_setColor(txt->text, txt->color);
    }
    if ( sys->seconds > 0.8) {
        sfClock_restart(sys->clock);
        txt->color = sfColor_fromRGB(255,255,255);
        sfText_setColor(txt->text, txt->color);
    }
}
