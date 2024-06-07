/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor_status
*/

#include "rpg.h"

sfRectangleShape* init_rect(sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape* rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 3);
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}

sfBool is_rect_clicked(sfRectangleShape* rect, sfVector2f mouse)
{
    sfFloatRect tmp = sfRectangleShape_getGlobalBounds(rect);
    if (mouse.y >= 1080 / 2) mouse.y += 50;
    return sfFloatRect_contains(&tmp, mouse.x, mouse.y);
}

void layer_clicked(sfSprite*** layer, sfVector2f mouse,
    selec_s* sel, int** ltab)
{
    int i = 0, j;
    while (layer[i] != NULL) {
        j = 0;
        while (layer[i][j] != NULL) {
            layer[i][j] = tile_layer_clicked(layer[i][j], mouse, sel,
                                                                &ltab[i][j]);
            j ++;
        }
        i ++;
    }
}

sfSprite* tile_layer_clicked(sfSprite* tile, sfVector2f mouse,
    selec_s* sel, int* id)
{
    sfVector2f pos;
    if (is_tile_clicked(tile, mouse)) {
        pos = sfSprite_getPosition(tile);
        tile = sfSprite_copy(sel->tile);
        sfSprite_setPosition(tile, pos);
        *id = sel->id + 1;
    }
    return tile;
}

sfBool is_tile_clicked(sfSprite* tile, sfVector2f mouse)
{
    sfFloatRect tmp = sfSprite_getGlobalBounds(tile);
    if (mouse.y >= 1080 / 4) mouse.y += 32;
    return sfFloatRect_contains(&tmp, mouse.x, mouse.y);
}
