/*
** EPITECH PROJECT, 2023
** button.c
** File description:
** button file
*/

#include "my.h"

int is_in_canva(sys_data *sys, sfVector2f positon, sfVector2u size)
{
    if ((sys->mouse.x >= positon.x + sys->pen->size &&
    sys->mouse.x <= positon.x + size.x - sys->pen->size) &&
    (sys->mouse.y >= positon.y - 13 + sys->pen->size &&
    sys->mouse.y <= positon.y + size.y - 14 - sys->pen->size)) {
        return 1;
    }
    return 0;
}

sfSprite *add_canva(canva_shape *canva)
{
    canva->pos_canva = (sfVector2f) {20, 180};
    canva->canva = sfSprite_create();
    sfTexture_updateFromImage(canva->canva_text, canva->canva_image, 0, 0);
    sfSprite_setTexture(canva->canva, canva->canva_text, 0);
    sfSprite_setPosition(canva->canva, canva->pos_canva);
    return canva->canva;
}

sfSprite *change_canva(canva_shape *canva, sfVector2i pos, sys_data *sys)
{
    for (int i = 0; i != sys->pen->size; i++) {
        for (int j = 0; j != sys->pen->size; j++) {
            sfImage_setPixel(canva->canva_image, pos.x - 20 + j,
            pos.y - 167 - i,
            sys->pen->color_pen);
            sfImage_setPixel(canva->canva_image, pos.x - 20 - j,
            pos.y - 167 + i,
            sys->pen->color_pen);
            sfImage_setPixel(canva->canva_image, pos.x - 20 + i,
            pos.y - 167 + j,
            sys->pen->color_pen);
            sfImage_setPixel(canva->canva_image, pos.x - 20 - j,
            pos.y - 167 - i,
            sys->pen->color_pen);
        }
    }
    return add_canva(canva);
}

int change_size_up(sys_data *sys)
{
    sys->pen->size++;
    sys->pen->st_size = my_strcat("Size :", take_nbr(sys->pen->size));
    sys->pen->text_size = init_text(sys->pen->size_pos, 25, sys->pen->st_size);
}

int change_size_down(sys_data *sys)
{
    sys->pen->size--;
    sys->pen->st_size = my_strcat("Size :", take_nbr(sys->pen->size));
    sys->pen->text_size = init_text(sys->pen->size_pos, 25, sys->pen->st_size);
}
