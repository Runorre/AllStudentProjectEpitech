/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor_layer
*/

#include "rpg.h"

palette_s* init_palette(void)
{
    palette_s* pal = NULL;
    int i = 0, j, x = 25, y = 13, size = 32;
    int a = 0, b = 0;
    while (i < y) {
        j = 0;
        while (j < x) {
            pal = add_paltile(pal, i, j, size);
            sfSprite_setPosition(pal->tile, (sfVector2f){
                    (1920 - 14 * 32) + (i * size),
                    (1080 / 3) + (j * size) - 300});
            j ++;
        }
        i ++;
    }
    return pal;
}

void draw_palette(sfRenderWindow* window, palette_s* pal)
{
    palette_s* tmp = pal;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->tile, NULL);
        tmp = tmp->next;
    }
}

palette_s* add_paltile(palette_s* pal, int i, int j, int size)
{
    palette_s* tmp = malloc(sizeof(palette_s));
    tmp->tile = init_palette_sprite(i, j, size);
    tmp->id = 25 * i + j;
    tmp->status = IDLE;
    if (pal == NULL) {
        tmp->next = NULL;
        return tmp;
    }
    tmp->next = pal;
    return tmp;
}

sfSprite* init_palette_sprite(int i, int j, int size)
{
    sfSprite* sprite = sfSprite_create();
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    sfTexture* texture;
    rect->height = size, rect->width = size;
    char* spritesheet = "./utilities/sprites/tiles_sheet.png";
    rect->top = i * size, rect->left = j * size;
    texture = sfTexture_createFromFile(spritesheet, rect);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void pal_clicked(palette_s** pal, sfMouseButtonEvent* mouse, selec_s** sel)
{
    palette_s* tmp = *pal;
    sfVector2f pos;
    int x = 25, i, j;
    while (tmp != NULL) {
        if (is_tile_clicked(tmp->tile, (sfVector2f){mouse->x, mouse->y})) {
            tmp->status = PRESSED;
            pos = sfSprite_getPosition(tmp->tile);
            i = (pos.x - (1920 - 14 * 32)) / 32;
            j = (pos.y - (1080 / 3 - 300)) / 32;
            (*sel)->id = i * 25 + j;
            (*sel)->tile = sfSprite_copy(tmp->tile);
            sfRectangleShape_setPosition((*sel)->rect, pos);
        } else {
            tmp->status = IDLE;
        }
        tmp = tmp->next;
    }
}
