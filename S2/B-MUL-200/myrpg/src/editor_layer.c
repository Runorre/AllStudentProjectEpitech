/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor_layer
*/

#include "rpg.h"

sfSprite*** init_void_layer(int x, int y, int size)
{
    int i = 0, j;
    sfSprite*** layer = malloc(sizeof(sfSprite**) * y + 1);
    sfSprite* void_tile = init_palette_sprite(1, 12, size);
    while (i < y) {
        j = 0;
        layer[i] = malloc(sizeof(sfSprite*) * x + 1);
        while (j < x) {
            layer[i][j] = sfSprite_copy(void_tile);
            sfSprite_setPosition(layer[i][j], (sfVector2f){
                3 + j * size, 3 + i * size});
            j ++;
        }
        layer[i][j] = NULL;
        i ++;
    }
    layer[i] = NULL;
    return layer;
}

void draw_layer_editor(sfRenderWindow* window, sfSprite*** layer)
{
    int i = 0, j;
    while (layer[i] != NULL) {
        j = 0;
        while (layer[i][j] != NULL) {
            sfRenderWindow_drawSprite(window, layer[i][j], NULL);
            j ++;
        }
        i ++;
    }
}

void draw_layers_editor(sfRenderWindow* window, ed_layers* layers)
{
    if (layers->v_bg == sfTrue)
        draw_layer_editor(window, layers->s_bg);
    if (layers->v_mid == sfTrue)
        draw_layer_editor(window, layers->s_mid);
    if (layers->v_fg == sfTrue)
        draw_layer_editor(window, layers->s_fg);
}

int** init_void_itab(int x, int y, int void_id)
{
    int i = 0, j;
    int** itab = malloc(sizeof(int*) * y);
    while (i < y) {
        j = 0;
        itab[i] = malloc(sizeof(int) * x);
        while (j < x) {
            itab[i][j] = void_id;
            j ++;
        }
        i ++;
    }
    return itab;
}

ed_layers* init_layers(int x, int y, char* name)
{
    ed_layers* layers = malloc(sizeof(ed_layers));
    int tile_size = 32, void_id = 38;
    layers->i_bg = init_void_itab(x, y, void_id);
    layers->i_mid = init_void_itab(x, y, void_id);
    layers->i_fg = init_void_itab(x, y, void_id);
    layers->s_bg = init_void_layer(x, y, tile_size);
    layers->s_mid = init_void_layer(x, y, tile_size);
    layers->s_fg = init_void_layer(x, y, tile_size);
    layers->v_bg = sfTrue;
    layers->v_mid = sfTrue;
    layers->v_fg = sfTrue;
    layers->current = BG;
    layers->name = name;
    layers->x = x;
    layers->y = y;
    return layers;
}
