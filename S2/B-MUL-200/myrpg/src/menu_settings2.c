/*
** EPITECH PROJECT, 2023
** aled
** File description:
** menu_settings2
*/

#include "rpg.h"

sfSprite **change_rect_set(sfSprite **tab_sprite, int pos)
{
    sfIntRect rect_sli = sfSprite_getTextureRect(tab_sprite[2]);
    sfIntRect rect_but = sfSprite_getTextureRect(tab_sprite[3]);
    if (pos == 0) {
        rect_sli.left = 6275; sfSprite_setTextureRect(tab_sprite[2], rect_sli);
    } else {
        rect_sli.left = 2435; sfSprite_setTextureRect(tab_sprite[2], rect_sli);
    } if (pos == 1) {
        rect_but.left = 4115; sfSprite_setTextureRect(tab_sprite[3], rect_but);
    } else {
        rect_but.left = 275; sfSprite_setTextureRect(tab_sprite[3], rect_but);
    } if (pos == 2) {
        rect_but.left = 4115; sfSprite_setTextureRect(tab_sprite[4], rect_but);
    } else {
        rect_but.left = 275; sfSprite_setTextureRect(tab_sprite[4], rect_but);
    }
}

sfBool events_set(sys_data *sys)
{
    if (sys->event.type == sfEvtKeyReleased &&
        sys->event.key.code == sfKeyEscape)
            return 1;
    switch (sys->event.type) {
    case sfEvtClosed:
        sfMusic_stop(sys->music);
        sfRenderWindow_close(sys->window);
        return 1;
        break;
    break;
        } return 0;
}

int move_button_set(sys_data *sys, int pos)
{
    if (sys->event.type == sfEvtKeyReleased &&
        (sys->event.key.code == sfKeyZ ||
        sys->event.key.code == sfKeyUp))
        pos--;
    if (sys->event.type == sfEvtKeyReleased &&
        (sys->event.key.code == sfKeyS ||
        sys->event.key.code == sfKeyDown))
        pos++;
    if (pos > 2)
        pos = 0;
    if (pos < 0)
        pos = 2;
    return pos;
}

int move_volume(sys_data *sys, sfSprite *volume_spri, int button)
{
    sfVector2f pos = sfSprite_getPosition(volume_spri);
    if (sys->event.type == sfEvtKeyPressed &&
    (sys->event.key.code == sfKeyQ || sys->event.key.code == sfKeyLeft)
    && sys->music_volume > 0 && button == 0) {
        sys->music_volume -= 2; pos.x -= 10;
        sfSprite_setPosition(volume_spri, pos);
    } if (sys->event.type == sfEvtKeyPressed &&
    (sys->event.key.code == sfKeyD || sys->event.key.code == sfKeyRight)
    && sys->music_volume < 100 && button == 0) {
        sys->music_volume += 2; pos.x += 10;
        sfSprite_setPosition(volume_spri, pos);
    } sys->pos_music_volume = pos;
}

void change_rez(sys_data *sys, int pos)
{
    if (sys->event.type == sfEvtKeyPressed &&
    sys->event.key.code == sfKeyReturn && pos == 1) {
        sfRenderWindow_destroy(sys->window);
        sfVideoMode mode = sfVideoMode_getDesktopMode();
        sys->window = sfRenderWindow_create(mode, "Spring",
        sfClose | sfFullscreen, NULL);
    } if (sys->event.type == sfEvtKeyPressed &&
    sys->event.key.code == sfKeyReturn && pos == 2) {
        sfRenderWindow_destroy(sys->window);
        sfVideoMode mode = sfVideoMode_getDesktopMode();
        sys->window = sfRenderWindow_create(mode, "Spring",
        sfClose | sfResize, NULL);
    }
}
