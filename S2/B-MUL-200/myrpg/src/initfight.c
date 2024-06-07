/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** fight
*/

#include "rpg.h"

void events_initfight(sys_data* sys)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            break;
        default:
            break;
    }
}

void anime_transition(sys_data* sys, map_s* map, sfVector2f pos, fight_s *f)
{
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(sys->window) && sys->fight == 1) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            events_initfight(sys);
        if (sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) > 0.1) {
            pos.x += 30.0;
            sfSprite_setPosition(f->trans, pos);
            sfClock_restart(clock);
        }
        if (pos.x >= sfView_getCenter(sys->view).x + 1920)
            sys->fight = 2;
        sfRenderWindow_clear(sys->window, sfBlack);
        if (pos.x < sfView_getCenter(sys->view).x - 1000)
            draw_map(sys->window, map, f->player);
        else
            draw_aera(f, sys);
        sfRenderWindow_drawSprite(sys->window, f->trans, NULL);
        sfRenderWindow_display(sys->window);
    } sfClock_destroy(clock);
}

fight_s *init_struct(champ_s *player, champ_s *enemie,
                        sfSprite *trans, sys_data *sys)
{
    fight_s *fight = malloc(sizeof(fight_s));
    fight->player = player;
    fight->enemie = enemie;
    sfVector2f s = sfView_getCenter(sys->view);
    sfSprite_setPosition(fight->player->battle,
    (sfVector2f) {s.x - 655.0, s.y + 5.0});
    sfSprite_setPosition(fight->enemie->sprite,
    (sfVector2f) {s.x + 555.0, s.y - 55.0});
    sfSprite_setScale(fight->player->battle,
    (sfVector2f) {3.5, 4.0});
    sfSprite_setScale(fight->enemie->sprite,
    (sfVector2f) {3.5, 4.0});
    fight->bg = sfSprite_create(); fight->trans = trans;
    sfTexture *t = sfTexture_createFromFile("./utilities/images/fight.png",
    NULL);
    sfSprite_setPosition(fight->bg,
    (sfVector2f) {s.x - 960.0, s.y - 540.0});
    sfSprite_setTexture(fight->bg, t, sfTrue);
    return init_struct2(fight, s, player, sys);
}

champ_s *init_enemy(char *texture, char *name)
{
    champ_s* enemy = malloc(sizeof(champ_s));
    enemy->name = name;
    enemy->stats = malloc(sizeof(stats_s));
    enemy->stats->hp = 1;
    enemy->stats->attack = 15;
    enemy->stats->defense = 0;
    enemy->level = malloc(sizeof(level_s));
    enemy->level->exp = 10;
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite,
        sfTexture_createFromFile(texture, NULL), sfTrue);
    return enemy;
}

int init_fight(champ_s *player, champ_s *enemie, sys_data* sys, map_s* map)
{
    sfTexture *text = sfTexture_createFromFile(
        "./utilities/images/transition.png", NULL);
    sfSprite *transition = sfSprite_create();
    sfSprite_setTexture(transition, text, sfTrue);
    sfVector2f pos_trans = sfView_getCenter(sys->view);
    fight_s *fight = init_struct(player, enemie, transition, sys);
    pos_trans.x -= 3000.0;
    pos_trans.y -= 540.0;
    sys->fight = 1;
    sfSprite_setPosition(transition, pos_trans);
    anime_transition(sys, map, pos_trans, fight);
    int end = fight_scene(fight, sys);
    sfSprite_destroy(transition);
    sfTexture_destroy(text);
    return end;
}
