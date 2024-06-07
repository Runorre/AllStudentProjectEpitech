/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** pause
*/

#include "rpg.h"

void settings(sys_data *sys)
{
    sfBool leave = 0; int pos = 0; sfText **text = init_text_set();
    sfSprite **tab_sprite = init_sprite_set(sys);
    while (leave != 1) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            leave = events_set(sys); move_volume(sys, tab_sprite[2], pos);
            pos = move_button_set(sys, pos); change_rez(sys, pos);
        } sfMusic_setVolume(sys->music, (10 * sys->music_volume / 50));
        change_rect_set(tab_sprite, pos);
        sfRenderWindow_clear(sys->window, sfBlack);
        for (int i = 0; tab_sprite[i] != NULL; i++) {
            sfRenderWindow_drawSprite(sys->window, tab_sprite[i], NULL);
        } for (int i = 0; text[i] != NULL; i++) {
            sfRenderWindow_drawText(sys->window, text[i], NULL);
        } sfRenderWindow_display(sys->window);
    }
}

sfBool check_pos(int pos, sys_data *sys, champ_s* mc)
{
    switch (pos) {
        case 0:
            settings(sys); return 0;
            break;
        case 1:
            save(mc); return 0;
            break;
        case 2:
            map_s* m; sfView_zoom(sys->view, 0.7);
            mc = recup_sauvegarde(&m); game(sys, m, mc);
            break;
        case 3:
            sfMusic_stop(sys->music);
            sfRenderWindow_close(sys->window);
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

sfSprite **change_rect_pause(sfSprite **tab_sprite, int pos)
{
    for (int i = 1; i != 5; i++) {
        sfIntRect rect_but = sfSprite_getTextureRect(tab_sprite[i]);
        if (pos == i - 1) {
            rect_but.left = 4115; sfSprite_setTextureRect(tab_sprite[i],
            rect_but);
        } else {
            rect_but.left = 275; sfSprite_setTextureRect(tab_sprite[i],
            rect_but);
        }
    }
}

sfBool events_pause(sys_data *sys, int pos, sfClock *clock, champ_s* mc)
{

    switch (sys->event.type) {
    case sfEvtClosed:
        sfMusic_stop(sys->music);
        sfRenderWindow_close(sys->window);
        return 1;
        break;
    case sfEvtKeyReleased:
        if (sys->event.key.code == sfKeyEscape &&
        sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 3) {
            return 1;
        } if (sys->event.key.code == sfKeyReturn)
            return check_pos(pos, sys, mc);
        break;
    break;
        } return 0;
}

void pause_game(sys_data *sys, champ_s* mc)
{
    sfClock *clock = sfClock_create();
    sfRenderWindow_setView(sys->window, sys->view);
    sfBool leave = 0; int pos = 0; sfText **text = init_text_pause();
    sfSprite **tab_sprite = init_sprite_pause();
    while (leave != 1) {
        change_rect_pause(tab_sprite, pos);
        sfRenderWindow_clear(sys->window, sfBlack);
        for (int i = 0; tab_sprite[i] != NULL; i++) {
            sfRenderWindow_drawSprite(sys->window, tab_sprite[i], NULL);
        } for (int i = 0; text[i] != NULL; i++) {
            sfRenderWindow_drawText(sys->window, text[i], NULL);
        } sfRenderWindow_display(sys->window);
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            leave = events_pause(sys, pos, clock, mc);
            pos = move_button_pause(sys, pos);
        }
    } if (sfRenderWindow_isOpen(sys->window) == sfTrue) {
        sfView_zoom(sys->view, 0.7);
    }
}
