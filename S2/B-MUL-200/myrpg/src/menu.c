/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** menu
*/

#include "rpg.h"
void check_choice(sys_data* sys, int *choice, menu_s *menu)
{
    champ_s* mc;
    switch (*choice) {
        case 0:
            sfMusic_stop(sys->music); sfView_zoom(sys->view, 0.7);
            map_s* m; mc = recup_sauvegarde(&m); game(sys, m, mc); break;
        case 1:
            mc = init_mc((sfVector2f){624 + 16, 960});
            sfView_zoom(sys->view, 0.7);
            sfRenderWindow_setVisible(sys->window, sfTrue);
            mc->name = get_name_champion(sys); save(mc) ;
            sfMusic_stop(sys->music); cinematique(sys);
            game(sys, map(1), mc); break;
        case 2: editor(36, 36, sys, "TMP"); break;
        case 3: menu_settings(sys, menu); break;
        case 4: sfRenderWindow_close(sys->window); break;
        default: break;
    }
}

void key_pressed(sys_data* sys, int* choice, menu_s *menu)
{
    switch (sys->event.key.code) {
        case sfKeyDown:
        case sfKeyS:
            *choice = (*choice == 4) ? 0 : *choice + 1;
            break;
        case sfKeyUp:
        case sfKeyZ:
            *choice = (*choice == 0) ? 4 : *choice - 1;
            break;
        case sfKeyReturn:
            check_choice(sys, choice, menu);
            break;
        default:
            break;
    }
}

void events_menu(sys_data* sys, int* choice, sfClock** joystick_clock,
menu_s* menu)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            break;
        case sfEvtKeyPressed:
            key_pressed(sys, choice, menu);
            break;
        default:
            joystick_menu(sys, choice, joystick_clock, menu);
            break;
    }
}

menu_s* init_menu(void)
{
    menu_s* menu = malloc(sizeof(menu_s));
    menu->choice = 0;
    menu->background = sfSprite_create();
    sfTexture* texture;
    menu->buttons_menu = init_buttons_list(
    my_str_to_word_array("Continue\nNew Game\nEditor\nSettings\n     Quit"),
        "./utilities/sprites/button.png",
        (sfVector2f){400, 400}, (sfVector2f){250, 75});
    texture = sfTexture_createFromFile("./utilities/images/main_back.png",
        NULL);
    sfSprite_setTexture(menu->background, texture, sfTrue);
    menu->joystick_clock = sfClock_create();
    return menu;
}

int menu(sys_data* sys)
{
    menu_s* menu = init_menu();
    sfMusic_play(sys->music);
    while (sfRenderWindow_isOpen(sys->window) && menu->choice != -1) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            events_menu(sys, &menu->choice, &menu->joystick_clock, menu);
        sfRenderWindow_clear(sys->window, sfBlack);
        sfRenderWindow_drawSprite(sys->window, menu->background, NULL);
        adapt_buttons_menu(&menu->buttons_menu, menu->choice);
        display_buttons(sys->window, menu->buttons_menu);
        sfRenderWindow_display(sys->window);
    }
    sfMusic_stop(sys->music);
    return 0;
}
