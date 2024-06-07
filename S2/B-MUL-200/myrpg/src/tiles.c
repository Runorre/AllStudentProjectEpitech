/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** tiles
*/

#include "rpg.h"

sfSprite* is_used(used_t* used, int id)
{
    used_t* tmp = used;
    while (tmp != NULL) {
        if (tmp->id == id) {
            return tmp->tile;
        }
        tmp = tmp->next;
    }
    return NULL;
}

used_t* add_used_tile(used_t* used, sfSprite* tile, int id)
{
    used_t* node = malloc(sizeof(used_t));
    node->tile = tile;
    node->id = id;
    if (used == NULL) {
        node->next = NULL;
        return node;
    }
    node->next = used;
    return node;
}

tile_s* get_tiles(nlist* num, ftile_s ftile)
{
    nlist* n = num; tile_s* tiles = NULL; used_t* used = NULL; sfSprite* tmp;
    int i = 0, j = 0;
    while (n != NULL) {
        if (i == ftile.x) {
            i = 0; j ++;
        }
        if (tmp = is_used(used, n->n)) {
            tiles = add_tile(tiles, sfSprite_copy(tmp));
            sfSprite_setPosition(tiles->tile,
                (sfVector2f){.x = i * ftile.tile_size,
                .y = j * ftile.tile_size});
        } else {
            tmp = get_sprite_tile(n->n, (sfVector2f){.x = i * ftile.tile_size,
                .y = j * ftile.tile_size}, ftile);
            tiles = add_tile(tiles, tmp);
            used = add_used_tile(used, tmp, n->n);
        }
        tiles->collide_type = set_collision(ftile, n->n);
        i ++; n = n->next;
        } return tiles;
}

tile_s* add_tile(tile_s* tiles, sfSprite* sprite)
{
    tile_s* tile = malloc(sizeof(tile_s));
    tile->tile = sprite;
    if (tiles == NULL) {
        tile->next = NULL;
        return tile;
    }
    tile->next = tiles;
    return tile;
}

sfSprite* get_sprite_tile(int n, sfVector2f pos, ftile_s ftile)
{
    sfSprite* sprite = sfSprite_create();
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    rect->height = ftile.tile_size;
    rect->width = ftile.tile_size;
    rect->top = ftile.tile_size * (n / ftile.l);
    rect->left = ftile.tile_size * (n % ftile.l - 1);
    sfTexture* texture = sfTexture_createFromFile(ftile.file, rect);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}
