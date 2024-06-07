/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** map_templates2
*/

#include "rpg.h"

map_s* map4_npc(map_s* map)
{
    sfVector2f pos = {31 * 32, 5 * 32}; int offset = 1 * 32;
    map->npc = add_npc(NULL,
        init_npc("utilities/sprites/3.png", "1", pos),
        init_rect((sfVector2f){pos.x - offset, pos.y - offset},
        (sfVector2f){offset * 2 + 32, offset * 2 + 32},
        sfColor_fromRGBA(0, 0, 255, 25)),
        create_dialogues("Encore un cul de sac...."));
    pos.x = 7 * 32, pos.y = 0; map->npc = add_npc(map->npc,
        init_npc("utilities/sprites/2.png", "2", pos),
        init_rect((sfVector2f){pos.x - offset, pos.y - offset},
        (sfVector2f){offset * 2 + 32, offset * 2 + 32},
        sfColor_fromRGBA(0, 0, 255, 25)),
        create_dialogues("Je me suis perdu !"));
    pos.x = 7 * 32, pos.y = 22 * 32; map->npc = add_npc(map->npc,
        init_npc("utilities/sprites/1.png", "3", pos),
        init_rect((sfVector2f){pos.x - offset, pos.y - offset},
        (sfVector2f){offset * 2 + 32, offset * 2 + 32},
        sfColor_fromRGBA(0, 0, 255, 25)),
        create_dialogues(NPC3)); return map;
}
