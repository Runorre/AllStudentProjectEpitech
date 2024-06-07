/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** pause2
*/

#include "rpg.h"

int move_button_pause(sys_data *sys, int pos)
{
    if (sys->event.type == sfEvtKeyReleased &&
        (sys->event.key.code == sfKeyZ ||
        sys->event.key.code == sfKeyUp))
        pos--;
    if (sys->event.type == sfEvtKeyReleased &&
        (sys->event.key.code == sfKeyS ||
        sys->event.key.code == sfKeyDown))
        pos++;
    if (pos > 3)
        pos = 0;
    if (pos < 0)
        pos = 3;
    return pos;
}

sfText *init_text(char *str, sfVector2f pos, int scale)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setCharacterSize(text, scale);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfFont *font = sfFont_createFromFile("utilities/fonts/ice.ttf");
    sfText_setFont(text, font);
    return text;
}

sfText **init_text_pause(void)
{
    int pos = 340;
    sfText **text = malloc(sizeof(sfText *) * 6);
    text[0] = init_text("PAUSE", (sfVector2f){850, 200}, 80);
    text[1] = init_text("Settings", (sfVector2f){850, pos}, 60);
    text[2] = init_text("Save", (sfVector2f){915, pos + 125 * 1}, 60);
    text[3] = init_text("Load", (sfVector2f){915, pos + 125 * 2}, 60);
    text[4] = init_text("Quit", (sfVector2f){915, pos + 125 * 3}, 60);
    text[5] = NULL;
    return text;
}

sfSprite **init_sprite_pause(void)
{
    sfVector2f pos = {770, 325};
    sfIntRect back_pause;
    sfSprite **tab_sprite = malloc(sizeof(sfSprite *) * 6);
    tab_sprite[0] = init_sprite("utilities/sprites/set_sheet.png");
    back_pause.left = 2435; back_pause.top = 1500;
    back_pause.height = 310; back_pause.width = 310;
    sfSprite_setPosition(tab_sprite[0], (sfVector2f){500, 50});
    sfSprite_setScale(tab_sprite[0], (sfVector2f){3, 3});
    sfSprite_setTextureRect(tab_sprite[0], back_pause);
    sfIntRect volume_rect_back;
    volume_rect_back.left = 275; volume_rect_back.top = 550;
    volume_rect_back.height = 360; volume_rect_back.width = 1125;
    for (int i = 1; i != 5; i++) {
        tab_sprite[i] = init_sprite("utilities/sprites/set_sheet.png");
        sfSprite_setTextureRect(tab_sprite[i], volume_rect_back);
        sfSprite_setPosition(tab_sprite[i], pos);
        sfSprite_setScale(tab_sprite[i], (sfVector2f){0.4, 0.3});
        pos.y = (pos.y + 125);
    } tab_sprite[5] = NULL;
    return (tab_sprite);
}
