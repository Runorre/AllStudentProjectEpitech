/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** first_map
*/

#include "rpg.h"

void draw_layer(sfRenderWindow* window, tile_s* layer)
{
    tile_s* tmp = layer;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->tile, NULL);
        tmp = tmp->next;
    }
}

void draw_map(sfRenderWindow* window, map_s* map, champ_s* mc)
{
    draw_layer(window, map->bg);
    draw_layer(window, map->mid);
    draw_npcs(window, map, mc);
    draw_layer(window, map->fg);
    adjust_dial_pos(&map->npc);
    draw_npc_dial(window, map->npc, mc);
}

map_s* init_map_from_file(ftile_s ftile, char* bg, char* mid, char* fg)
{
    map_s* map = malloc(sizeof(map_s));
    if (fg != NULL)
        map->fg = get_tiles(init_nlist(fg), ftile);
    if (mid != NULL)
        map->mid = get_tiles(init_nlist(mid), ftile);
    if (bg != NULL)
        map->bg = get_tiles(init_nlist(bg), ftile);
    return map;
}
