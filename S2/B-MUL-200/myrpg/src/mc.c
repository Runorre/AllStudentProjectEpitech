/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** mc
*/

#include "rpg.h"

void set_view(sys_data* sys, sfSprite* sprite)
{
    sfView_setCenter(sys->view, sfSprite_getPosition(sprite));
    sfRenderWindow_setView(sys->window, sys->view);
}

sfVector2f move_offset(sfKeyCode key, champ_s** mc)
{
    int move = 5;
    sfVector2f offset = {0, 0};
    switch (key) {
        case sfKeyUp: case sfKeyZ:
            (*mc)->rect->top = 0; offset.y = -move; break;
        case sfKeyDown: case sfKeyS:
            (*mc)->rect->top = 47; offset.y = move; break;
        case sfKeyLeft: case sfKeyQ:
            (*mc)->rect->top = 47 * 2; offset.x = -move; break;
        case sfKeyRight: case sfKeyD:
            (*mc)->rect->top = 47 * 3; offset.x = move; break;
        default: break;
    }
    return offset;
}

void move_player(sfKeyCode key, champ_s** mc, tile_s* collisions)
{
    sfVector2f offset; sfTexture* texture;
    sfSprite* tmp = sfSprite_copy((*mc)->sprite);
    if (sfTime_asSeconds(sfClock_getElapsedTime((*mc)->clock_move)) > 0.003) {
        offset = move_offset(key, mc);
        if (offset.x == 0 && offset.y == 0) return;
        sfSprite_move((*mc)->sprite, offset);
        sfClock_restart((*mc)->clock_move);
    } if (sfTime_asSeconds(sfClock_getElapsedTime((*mc)->clock_spri)) > 0.05) {
        sfClock_restart((*mc)->clock_spri);
        if ((*mc)->rect->left >= (*mc)->rect->width * 7) {
            (*mc)->rect->left = 0;
        } else {
            (*mc)->rect->left += (*mc)->rect->width;
        }
        texture = sfTexture_createFromFile((*mc)->sheet, (*mc)->rect);
        sfSprite_setTexture((*mc)->sprite, texture, sfTrue);
    } if (player_collide(*mc, collisions)) {
        (*mc)->sprite = tmp;
    } texture = sfTexture_createFromFile((*mc)->sheet, (*mc)->rect);
    sfSprite_setTexture((*mc)->sprite, texture, sfTrue);
}

champ_s* init_stat(champ_s *mc)
{
    mc->level = malloc(sizeof(level_s));
    mc->level->lvl = 1;
    mc->level->exp = 0;
    mc->stats = malloc(sizeof(stats_s));
    mc->stats->attack = 13;
    mc->stats->defense = 3;
    mc->stats->magie = 4;
    mc->stats->hp = 30;
    mc->stats->max_hp = 30;
    mc->stats->mp = 15;
    mc->stats->max_mp = 15;
    mc->battle = sfSprite_create();
    sfTexture *t = sfTexture_createFromFile("./utilities/sprites/kingf.png",
        NULL);
    sfSprite_setTexture(mc->battle, t, sfTrue);
    mc->spells = get_spring(mc);
    return mc;
}

champ_s* init_mc(sfVector2f pos)
{
    champ_s* mc = malloc(sizeof(champ_s));
    mc->rect = malloc(sizeof(sfIntRect));
    mc->sheet = "./utilities/sprites/king_moves.png";
    mc->name = "A";
    mc->inv = NULL; mc->spells = NULL; mc->trophee = NULL;
    mc->q1 = mc->q2 = mc->q3 = false;
    mc->sprite = sfSprite_create();
    mc->rect->top = 0; mc->rect->left = 0;
    mc->rect->height = 47; mc->rect->width = 30;
    sfTexture* texture = sfTexture_createFromFile(mc->sheet, mc->rect);
    sfSprite_setTexture(mc->sprite, texture, sfTrue);
    sfSprite_setPosition(mc->sprite, pos);
    mc->clock_move = sfClock_create(); mc->clock_spri = sfClock_create();
    return init_stat(mc);
}
