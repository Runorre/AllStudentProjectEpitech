/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** animation
*/

#include "my.h"


void flylateral(struct sprite *sp, struct system_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds > 0.03) {
        if (sp->pos.x > 2000 || sp->pos.y < -100) {
            randomduck(&(*sp), &(*sys));
            sys->live--;
        }
        sp->pos.x += 8;
        sp->pos.y -= 8;
        sfSprite_setPosition(sp->sp, sp->pos);
    }
    if ( sys->seconds > 0.1) {
        sfClock_restart(sys->clock);
        if (sys->rect.left >= 160)
            sys->rect.left = 117;
        else
            sys->rect.left += 34;
        sfSprite_setTextureRect(sp->sp, sys->rect);
        sfSound_play(sys->sound.fly);
    }
}

void flylateralrever(struct sprite *sp, struct system_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds > 0.03) {
        if (sp->pos.x > 2000 || sp->pos.y < -100) {
            randomduck(&(*sp), &(*sys));
            sys->live--;
        }
        sp->pos.x -= 8;
        sp->pos.y -= 8;
        sfSprite_setPosition(sp->sp, sp->pos);
    }
    if ( sys->seconds > 0.1) {
        sfClock_restart(sys->clock);
        if (sys->rect.left < 420)
            sys->rect.left = 460;
        else
            sys->rect.left -= 34;
        sfSprite_setTextureRect(sp->sp, sys->rect);
        sfSound_play(sys->sound.fly);
    }
}

void deadanim(struct sprite *sp, struct system_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds < 0.6) {
        if (sp->inverted == 0) {
            sys->rect.left = 222;
            sfSprite_setTextureRect(sp->sp, sys->rect);
        } else {
            sys->rect.left = 665;
            sfSprite_setTextureRect(sp->sp, sys->rect);
        }
    } else {
        sfClock_restart(sys->clock);
        sys->rect.left = 265;
        sp->status = 4;
        sfSprite_setTextureRect(sp->sp, sys->rect);
        sfSound_play(sys->sound.fall);
    }
}

void fallanime(struct sprite *sp, struct system_data *sys)
{
    sys->time = sfClock_getElapsedTime(sys->clock);
    sys->seconds = sys->time.microseconds / 1000000.0;
    if (sys->seconds > 0.01) {
        if (sp->pos.x < 100 || sp->pos.y > 750) {
            sfSound_stop(sys->sound.fall);
            randomduck(&(*sp), &(*sys));
        }
        sp->pos.y += 12;
        sfSprite_setPosition(sp->sp, sp->pos);
    }
    if (sys->seconds > 0.08) {
        sfClock_restart(sys->clock);
        if (sys->rect.left >= 340)
            sys->rect.left = 265;
        else
            sys->rect.left += 30;
        sfSprite_setTextureRect(sp->sp, sys->rect);
    }
}

void animation(struct sprite *sp, struct system_data *sys)
{
    if (sp->status == 1)
        flylateral(&(*sp), &(*sys));
    if (sp->status == 2)
        flylateralrever(&(*sp), &(*sys));
    if (sp->status == 3)
        deadanim(&(*sp), &(*sys));
    if (sp->status == 4) {
        fallanime(&(*sp), &(*sys));
    }
    sfRenderWindow_drawSprite(sys->window, sp->sp, NULL);
}
