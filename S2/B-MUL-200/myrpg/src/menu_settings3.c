/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** menu_settings3
*/

#include "rpg.h"

void menu_settings(sys_data *sys, menu_s *menu)
{
    sfBool leave = 0; int pos = 0; sfText **text = init_text_set();
    sfSprite **tab_sprite = init_sprite_set(sys);
    while (leave != 1) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            leave = events_set(sys); move_volume(sys, tab_sprite[2], pos);
            pos = joystick_set(sys, pos, menu->joystick_clock);
            pos = move_button_set(sys, pos); change_rez(sys, pos);
            move_volume_contr(sys, tab_sprite[2], pos,
            menu->joystick_clock);
        } sfMusic_setVolume(sys->music, (10 * sys->music_volume / 50));
        change_rect_set(tab_sprite, pos);
        sfRenderWindow_clear(sys->window, sfBlack);
        sfRenderWindow_drawSprite(sys->window, menu->background, NULL);
        display_buttons(sys->window, menu->buttons_menu);
        for (int i = 0; tab_sprite[i] != NULL; i++) {
            sfRenderWindow_drawSprite(sys->window, tab_sprite[i], NULL);
        } for (int i = 0; text[i] != NULL; i++) {
            sfRenderWindow_drawText(sys->window, text[i], NULL);
        } sfRenderWindow_display(sys->window);
    }
}
