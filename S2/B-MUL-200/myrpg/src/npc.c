/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** npc
*/

#include "rpg.h"

champ_s* init_npc(char* sheet, char* name, sfVector2f pos)
{
    champ_s* mc = malloc(sizeof(champ_s));
    mc->sheet = sheet;
    mc->name = name;
    mc->inv = NULL;
    mc->spells = NULL;
    mc->stats = NULL;
    mc->sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(mc->sheet, NULL);
    sfSprite_setTexture(mc->sprite, texture, sfTrue);
    sfSprite_setPosition(mc->sprite, pos);
    return mc;
}

void draw_npc_dial(sfRenderWindow* win, lnpc_s* npc, champ_s* mc)
{
    lnpc_s* tmp = npc;
    while (tmp != NULL) {
        if (tmp->dial->show == sfTrue) {
            draw_dial(tmp->dial, win);
        }
        tmp = tmp->next;
    }
}

void draw_npcs(sfRenderWindow* win, map_s* map, champ_s* mc)
{
    lnpc_s* tmp = map->npc;
    sfVector2f size_mc = {32.0, 32.0};
    sfVector2f pos1 = sfSprite_getPosition(mc->sprite);
    sfVector2f pos2;
    if (map->npc == NULL) draw_boss(win, map, mc);
    while (tmp != NULL) {
        pos2 = sfSprite_getPosition(tmp->mod->sprite);
        if (pos1.y >= pos2.y) {
            sfRenderWindow_drawSprite(win, tmp->mod->sprite, NULL);
            draw_boss(win, map, mc);
        } else {
            sfRenderWindow_drawSprite(win, mc->sprite, NULL);
            draw_boss(win, map, mc);
            sfRenderWindow_drawSprite(win, tmp->mod->sprite, NULL);
        } if (tp_collision(mc->sprite, size_mc, tmp->area)) {
            tmp->dial->show = sfTrue;
        } else {
            tmp->dial->show = sfFalse;
        } tmp = tmp->next;
    }
}

lnpc_s* add_npc(lnpc_s* head, champ_s* mod, sfRectangleShape* area,
    dial_s* dial)
{
    lnpc_s* npc = malloc(sizeof(lnpc_s));
    npc->mod = mod;
    npc->area = area;
    npc->dial = dial;
    if (head == NULL) {
        npc->next = NULL;
        return npc;
    }
    npc->next = head;
    return npc;
}
