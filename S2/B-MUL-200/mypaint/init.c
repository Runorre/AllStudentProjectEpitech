/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include "my.h"

sfRectangleShape *init_button (sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape,size);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    sfRectangleShape_setOutlineThickness(shape, 1);
    return shape;
}

sfSprite *set_pencil(sys_data *sys)
{
    sfTexture *textpen;
    sys->sprites->pen_active = sfTrue;
    sys->sprites->pos_pen = (sfVector2f) {210, 80};
    sfVector2f scale = {0.35, 0.35};
    textpen = sfTexture_createFromFile("crayon.png", NULL);
    sys->sprites->size_pen = (sfVector2u) {45, 50};
    sys->sprites->pen = sfSprite_create();
    sfSprite_setTexture(sys->sprites->pen, textpen, sfTrue);
    sfSprite_setScale(sys->sprites->pen, scale);
    sfSprite_setPosition(sys->sprites->pen, sys->sprites->pos_pen);
}

sfSprite *set_eraser(sys_data *sys)
{
    sfTexture *text_erase;
    sys->sprites->erase_active = sfTrue;
    sys->sprites->pos_erase = (sfVector2f) {280, 80};
    sfVector2f scale = {0.065, 0.065};
    text_erase = sfTexture_createFromFile("gomme.png", NULL);
    sys->sprites->size_erase = (sfVector2u) {45, 50};
    sys->sprites->eraser = sfSprite_create();
    sfSprite_setTexture(sys->sprites->eraser, text_erase, sfTrue);
    sfSprite_setScale(sys->sprites->eraser, scale);
    sfSprite_setPosition(sys->sprites->eraser, sys->sprites->pos_erase);
}

sfText *init_text (sfVector2f position, int size, char *str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font2.TTF");
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, str);
    sfText_setColor(text, sfBlack);
    return text;
}
