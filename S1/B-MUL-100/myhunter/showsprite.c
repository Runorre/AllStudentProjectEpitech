/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** showsprite
*/

#include "my.h"

void show_hud(struct HUD *hud, struct system_data *sys)
{
    sfRenderWindow_drawSprite(sys->window, hud->blank.sp, NULL);
    sfRenderWindow_drawSprite(sys->window, hud->shot.sp, NULL);
    if (sys->live >= 1)
        sfRenderWindow_drawSprite(sys->window, hud->bullts1.sp, NULL);
    if (sys->live >= 2)
        sfRenderWindow_drawSprite(sys->window, hud->bullts2.sp, NULL);
    if (sys->live == 3)
        sfRenderWindow_drawSprite(sys->window, hud->bullts3.sp, NULL);
    sfRenderWindow_drawText(sys->window, hud->score.text, NULL);
}

void show_bg(struct BG *bg, struct system_data *sys)
{
    sfRenderWindow_drawSprite(sys->window, bg->bg.sp, NULL);
    animation(&bg->duck, &(*sys));
    sfRenderWindow_drawSprite(sys->window, bg->front.sp, NULL);
}
