/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_up_down
*/

#include "my.h"

sfSprite *set_down(sys_data *sys)
{
    sfTexture *text_erase;
    sys->sprites->down_active = sfFalse;
    sys->sprites->pos_down = (sfVector2f) {580, 80};
    sfVector2f scale = {0.4, 0.4};
    text_erase = sfTexture_createFromFile("down.png", NULL);
    sys->sprites->size_down = (sfVector2u) {45, 50};
    sys->sprites->down = sfSprite_create();
    sfSprite_setTexture(sys->sprites->down, text_erase, sfTrue);
    sfSprite_setScale(sys->sprites->down, scale);
    sfSprite_setPosition(sys->sprites->down, sys->sprites->pos_down);
}

sfSprite *set_up(sys_data *sys)
{
    sfTexture *text_erase;
    sys->sprites->up_active = sfFalse;
    sys->sprites->pos_up = (sfVector2f) {500, 82};
    sfVector2f scale = {0.4, 0.4};
    text_erase = sfTexture_createFromFile("up.png", NULL);
    sys->sprites->size_up = (sfVector2u) {45, 50};
    sys->sprites->up = sfSprite_create();
    sfSprite_setTexture(sys->sprites->up, text_erase, sfTrue);
    sfSprite_setScale(sys->sprites->up, scale);
    sfSprite_setPosition(sys->sprites->up, sys->sprites->pos_up);
}
