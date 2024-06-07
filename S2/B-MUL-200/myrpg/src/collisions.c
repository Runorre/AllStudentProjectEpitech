/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** collisions
*/

#include "rpg.h"

int set_collision(ftile_s ftile, int id)
{

    if (ftile.l == 25) {
        if (id == 38) {
            return 0;
        } else {
            return 1;
        }
    }
    if (ftile.l == 26) {
        if (id == 39) {
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
}

int sprite_collisions(sfSprite* a, sfVector2f size_a,
    sfSprite* b, sfVector2f size_b)
{
    sfVector2f pos_a = sfSprite_getPosition(a);
    sfVector2f pos_b = sfSprite_getPosition(b);
    pos_b.y -= size_b.y;
    if ((pos_a.x) < (pos_b.x + size_b.x)
        && (pos_a.x + size_a.x) > (pos_b.x)
        && (pos_a.y) < (pos_b.y + size_b.y)
        && (pos_a.y + size_a.y) > (pos_b.y)) {
        return 1;
    }
    return 0;
}

int player_collide2(tile_s* tmp, champ_s* mc)
{
    sfVector2f size_mc = {32.0, 32.0};
    sfVector2f size_tile = {32.0, 32.0};
    if (tmp->collide_type == 1) {
        if (sprite_collisions(mc->sprite, size_mc, tmp->tile, size_tile)) {
            return 1;
        }
    }
    return 0;
}

int player_collide(champ_s* mc, tile_s* collisions)
{
    tile_s* tmp = collisions;
    while (tmp != NULL) {
        if (player_collide2(tmp, mc))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
