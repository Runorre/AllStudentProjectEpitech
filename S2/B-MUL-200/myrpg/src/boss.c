/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** boss
*/

#include "rpg.h"

void draw_boss(sfRenderWindow* win, map_s* map, champ_s* mc)
{
    sfVector2f pos1 = sfSprite_getPosition(mc->sprite);
    sfVector2f pos2;
    if (map->boss != NULL && ((map->id == 2 && mc->q1 == 0) ||
        (map->id == 3 && mc->q2 == 0) || (map->id == 5 && mc->q3 == 0))) {
        pos2 = sfSprite_getPosition(map->boss->sprite);
        if (pos1.y >= pos2.y) {
            sfRenderWindow_drawSprite(win, map->boss->sprite, NULL);
            sfRenderWindow_drawSprite(win, mc->sprite, NULL);
        } else {
            sfRenderWindow_drawSprite(win, mc->sprite, NULL);
            sfRenderWindow_drawSprite(win, map->boss->sprite, NULL);
        }
    } else {
        sfRenderWindow_drawSprite(win, mc->sprite, NULL);
    }
}

champ_s* init_boss(int id)
{
    switch (id) {
        case 2:
            return boss_summer();
        case 3:
            return boss_autumn();
        case 5:
            return boss_alter();
        default:
            break;
    }
    return NULL;
}

champ_s *boss_summer(void)
{
    champ_s *boss = malloc(sizeof(champ_s));
    boss->name = "Sommar";
    boss->stats = malloc(sizeof(stats_s));
    boss->stats->hp = 35;
    boss->stats->attack = 15;
    boss->stats->defense = 2;
    boss->level = malloc(sizeof(level_s));
    boss->level->exp = 10;
    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite,
    sfTexture_createFromFile("./utilities/sprites/sommar.png",
    NULL), sfTrue);
    sfSprite_setPosition(boss->sprite, (sfVector2f){17 * 32, 25 * 32});
    return boss;
}

champ_s *boss_autumn(void)
{
    champ_s *boss = malloc(sizeof(champ_s));
    boss->name = "Host";
    boss->stats = malloc(sizeof(stats_s));
    boss->stats->hp = 80;
    boss->stats->attack = 27;
    boss->stats->defense = 7;
    boss->level = malloc(sizeof(level_s));
    boss->level->exp = 10;
    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite,
    sfTexture_createFromFile("./utilities/sprites/host.png",
    NULL), sfTrue);
    sfSprite_setPosition(boss->sprite, (sfVector2f){13 * 32, 10 * 32});
    return boss;
}

champ_s *boss_alter(void)
{
    champ_s *boss = malloc(sizeof(champ_s));
    boss->name = "Vinter";
    boss->stats = malloc(sizeof(stats_s));
    boss->stats->hp = 110;
    boss->stats->attack = 42;
    boss->stats->defense = 10;
    boss->level = malloc(sizeof(level_s));
    boss->level->exp = 42;
    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite,
    sfTexture_createFromFile("./utilities/sprites/egof.png",
    NULL), sfTrue);
    sfSprite_setPosition(boss->sprite, (sfVector2f){17 * 32, 2 * 32});
    return boss;
}
