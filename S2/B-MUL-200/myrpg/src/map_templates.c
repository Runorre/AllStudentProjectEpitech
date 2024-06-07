/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** map_templates
*/

#include "rpg.h"

map_s* map5(void)
{
    ftile_s ftile = { .file = "./utilities/sprites/tiles_sheet.png",
        .l = 26, .tile_size = 32, .x = 25, .y = 26};
    map_s* map = init_map_from_file( ftile, "./utilities/map5/map5_bg",
        "./utilities/map5/map5_mid", "./utilities/map5/map5_fg");
    map->tp = add_tp(NULL ,init_rect(
        (sfVector2f){5 * 32, 26 * 32}, (sfVector2f){32 * 14, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 4,
            (sfVector2f){17 * 32, 32});
    map->npc = NULL;
    map->id = 5;
    return map;
}

map_s* map4(void)
{
    ftile_s ftile = { .file = "./utilities/sprites/tiles_sheet.png",
        .l = 26, .tile_size = 32, .x = 43, .y = 33};
    map_s* map = init_map_from_file( ftile, "./utilities/map4/map4_bg",
        "./utilities/map4/map4_mid", "./utilities/map4/map4_fg");
    map->tp = add_tp(NULL ,init_rect(
        (sfVector2f){32, 33 * 32}, (sfVector2f){32 * 2, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 3,
            (sfVector2f){12 * 32, 8 * 32});
    map->tp = add_tp(map->tp ,init_rect(
        (sfVector2f){17 * 32, 0}, (sfVector2f){32 * 2, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 5,
            (sfVector2f){11 * 32, 24 * 32});
    map = map4_npc(map);
    map->id = 4;
    return map;
}

map_s* map3(void)
{
    ftile_s ftile = { .file = "./utilities/sprites/tiles_sheet.png",
        .l = 25, .tile_size = 32, .x = 25, .y = 30};
    map_s* map = init_map_from_file( ftile, "./utilities/map3/map3_bg",
        "./utilities/map3/map3_mid", "./utilities/map3/map3_fg");
    map->tp = add_tp(NULL, init_rect(
        (sfVector2f){11 * 32, 30 * 32}, (sfVector2f){2 * 32, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 2, (sfVector2f){26 * 32, 0});
    map->tp = add_tp(map->tp, init_rect(
        (sfVector2f){11 * 32, 6 * 32}, (sfVector2f){3 * 32, 2 * 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 4, (sfVector2f){32 + 16, 32 * 32});
    map->npc = NULL;
    map->id = 3;
    return map;
}

map_s* map2(void)
{
    sfVector2f pos = {15 * 32, 25 * 32};
    int offset = 4 * 32;
    ftile_s ftile = { .file = "./utilities/sprites/tiles_sheet.png",
        .l = 25, .tile_size = 32, .x = 36, .y = 36};
    map_s* map = init_map_from_file(ftile, "./utilities/map2/map2_bg",
        "./utilities/map2/map2_mid", "./utilities/map2/map2_fg");
    map->tp = add_tp(NULL, init_rect(
        (sfVector2f){32 * 4, -32}, (sfVector2f){32 * 5, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 1, (sfVector2f){32 * 20, 32 * 36});
    map->tp = add_tp(map->tp,init_rect(
        (sfVector2f){32 * 24, -32}, (sfVector2f){32 * 5, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 3,
            (sfVector2f){11 * 32 + 16, 29 * 32});
    map->npc = add_npc(NULL,
        init_npc("utilities/sprites/druid.png", "Sylvia", pos),
        init_rect((sfVector2f){pos.x - offset, pos.y - offset},
        (sfVector2f){offset * 2 + 32, offset * 2 + 32},
        sfColor_fromRGBA(0, 0, 255, 25)),
        create_dialogues("Aidez-moi par pitie !"));
    map->id = 2; return map;
}

map_s* map1(void)
{
    sfVector2f pos = {32 * 20, 17 * 36};
    int offset = 9 * 32;
    ftile_s ftile = {.file = "./utilities/sprites/tiles_sheet.png",
        .l = 25, .tile_size = 32, .x = 41, .y = 39};
    map_s* map = init_map_from_file( ftile, "./utilities/map1/map1_bg",
        "./utilities/map1/map1_mid", "./utilities/map1/map1_fg");
    map->tp = add_tp(NULL, init_rect(
        (sfVector2f){32 * 19, 32 * 38}, (sfVector2f){32 * 3, 32},
        sfColor_fromRGBA(255, 0, 0, 25)), 2, (sfVector2f){6 * 32, 0});
    map->npc = add_npc(NULL,
        init_npc("utilities/sprites/druid.png", "Sylvia", pos),
        init_rect((sfVector2f){pos.x - offset, pos.y - offset},
        (sfVector2f){offset * 2 + 32, offset * 2 + 32},
        sfColor_fromRGBA(0, 0, 255, 25)),
        create_dialogues(TUTO));
    map->id = 1;
    return map;
}
