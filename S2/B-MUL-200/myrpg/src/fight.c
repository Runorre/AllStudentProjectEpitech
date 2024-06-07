/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** fight
*/

#include "rpg.h"

void events_fight(sys_data* sys, fight_s *fight, sfMusic *battle)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfMusic_stop(battle);
            sfRenderWindow_close(sys->window);
            break;
        case sfEvtKeyPressed:
            if (sys->event.key.code == sfKeyEscape) {
                sfView_reset(sys->view, sys->rect_view);
                sfRenderWindow_setView(sys->window, sys->view);
                pause_game(sys, fight->player);
                sfView_setCenter(sys->view,
                    sfSprite_getPosition(fight->player->sprite));
                sfRenderWindow_setView(sys->window, sys->view);
            } down_menu_event(fight, sys, sys->event.key.code);
            break;
        default:
            break;
    }
}

int draw_aera(fight_s *fight, sys_data *sys)
{
    sfView_reset(sys->view, sys->rect_view);
    sfView_setCenter(sys->view, sfSprite_getPosition(fight->player->sprite));
    sfRenderWindow_setView(sys->window, sys->view);
    sfRenderWindow_drawSprite(sys->window, fight->bg, NULL);
    sfRenderWindow_drawSprite(sys->window, fight->player->battle, NULL);
    if (fight->down_status != 3 && fight->down_status != 11)
        sfRenderWindow_drawSprite(sys->window, fight->enemie->sprite, NULL);
}

int draw_hud(fight_s *fight, sys_data *sys)
{
    sfRenderWindow_drawSprite(sys->window, fight->box, NULL);
    if (fight->down_status == 0 || fight->down_status == 11)
        sfRenderWindow_drawText(sys->window, fight->chos_act, NULL);
    if (fight->down_status == 4)
        show_list_spell(fight, sys);
    if (fight->down_status != 11)
        sfRenderWindow_drawSprite(sys->window, fight->cursor, NULL);
}

void check_end(fight_s *fight, sys_data *sys, sfMusic *battle)
{
    if (fight->enemie->stats->hp <= 0 && fight->down_status != 3 &&
    fight->down_status != 7) {
        fight->down_status = 3;
        char *msg = my_strcat("Vous avez battue ", fight->enemie->name);
        sfMusic_stop(battle);
        sfMusic_setVolume(fight->vic, (10 * sys->music_volume / 25));
        sfMusic_play(fight->vic);
        sfText_setString(fight->upper_msg, msg);
        fight->clock = sfClock_create();
        free(msg);
        return;
    }
    if (fight->player->stats->hp <= 0 && fight->down_status != 3 &&
    fight->down_status != 7) {
        fight->down_status = 7;
        sfMusic_stop(battle);
        sfMusic_play(fight->gm);
        sfText_setString(fight->upper_msg, "Vous etes mort !");
        fight->clock = sfClock_create(); return;
    }
}

int fight_scene(fight_s *fight, sys_data *sys)
{
    sfMusic *battle = sfMusic_createFromFile("./utilities/musics/fight.ogg");
    sfMusic_setLoop(battle, sfTrue);
    sfMusic_setVolume(battle, (10 * sys->music_volume / 50));
    sfMusic_play(battle);
    while (sfRenderWindow_isOpen(sys->window) && sys->fight == 2) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            events_fight(sys, fight, battle);
        sfRenderWindow_clear(sys->window, sfBlack);
        draw_aera(fight, sys);
        if (fight->down_status == 0 || fight->down_status == 4)
            draw_hud(fight, sys);
        if ((fight->down_status != 0 && fight->down_status != 4) ||
        fight->no_mana)
            draw_upper(fight, sys);
        draw_life(fight, sys);
        check_end(fight, sys, battle);
        sfRenderWindow_display(sys->window);
    }
    return end_action(battle, fight, sys);
}
