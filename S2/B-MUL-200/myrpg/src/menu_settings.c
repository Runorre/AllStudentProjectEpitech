/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** menu_settings
*/

#include "rpg.h"

sfText *create_text_set(char *str, sfVector2f pos, int scale)
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

sfText **init_text_set(void)
{
    sfText **text = malloc(sizeof(sfText *) * 6);
    text[0] = create_text_set("SETTINGS", (sfVector2f){775, 200}, 80);
    text[1] = create_text_set("Volume", (sfVector2f){850, 300}, 60);
    text[2] = create_text_set("Resolution", (sfVector2f){800, 500}, 60);
    text[3] = create_text_set("full screen", (sfVector2f){772, 620}, 25);
    text[4] = create_text_set("Resize", (sfVector2f){1065, 620}, 25);
    text[5] = NULL;
    return text;
}

sfSprite **change_rect(sfSprite **tab_sprite, int pos)
{
    sfIntRect rect_sli = sfSprite_getTextureRect(tab_sprite[2]);
    sfIntRect rect_but = sfSprite_getTextureRect(tab_sprite[3]);
    if (pos == 0) {
        rect_sli.left = 6275; sfSprite_setTextureRect(tab_sprite[2], rect_sli);
    } else {
        rect_sli.left = 2435; sfSprite_setTextureRect(tab_sprite[2], rect_sli);
    }
    if (pos == 1) {
        rect_but.left = 4115; sfSprite_setTextureRect(tab_sprite[3], rect_but);
    } else {
        rect_but.left = 275; sfSprite_setTextureRect(tab_sprite[3], rect_but);
    } if (pos == 2) {
        rect_but.left = 4115; sfSprite_setTextureRect(tab_sprite[4], rect_but);
    } else {
        rect_but.left = 275; sfSprite_setTextureRect(tab_sprite[4], rect_but);
    }
}

sfSprite **init_sprite_set2(sys_data *sys, sfSprite **tab_sprite)
{
    sfIntRect back_menu;
    tab_sprite[2] = init_sprite("utilities/sprites/set_sheet.png");
    back_menu.left = 2435; back_menu.top = 1500;
    back_menu.height = 310; back_menu.width = 310;
    sfSprite_setPosition(tab_sprite[2],
    (sfVector2f){(sys->music_volume * 5) + 700, 405});
    sfSprite_setScale(tab_sprite[2], (sfVector2f){0.2, 0.2});
    sfSprite_setTextureRect(tab_sprite[2], back_menu);
    tab_sprite[3] = init_sprite("utilities/sprites/set_sheet.png");
    back_menu.left = 275; back_menu.top = 550;
    back_menu.height = 360; back_menu.width = 1125;
    sfSprite_setPosition(tab_sprite[3], (sfVector2f){750, 600});
    sfSprite_setScale(tab_sprite[3], (sfVector2f){0.2, 0.2});
    sfSprite_setTextureRect(tab_sprite[3], back_menu);
    tab_sprite[4] = init_sprite("utilities/sprites/set_sheet.png");
    sfSprite_setPosition(tab_sprite[4], (sfVector2f){1000, 600});
    sfSprite_setScale(tab_sprite[4], (sfVector2f){0.2, 0.2});
    sfSprite_setTextureRect(tab_sprite[4], back_menu);
    tab_sprite[5] = NULL;
    return tab_sprite;
}

sfSprite **init_sprite_set(sys_data *sys)
{
    sfIntRect back_menu; sfSprite **tab_sprite = malloc(sizeof(sfSprite *) * 5);
    tab_sprite[0] = init_sprite("utilities/sprites/set_sheet.png");
    back_menu.left = 2435; back_menu.top = 1500;
    back_menu.height = 310; back_menu.width = 310;
    sfSprite_setPosition(tab_sprite[0], (sfVector2f){500, 50});
    sfSprite_setScale(tab_sprite[0], (sfVector2f){3, 3});
    sfSprite_setTextureRect(tab_sprite[0], back_menu);
    tab_sprite[1] = init_sprite("utilities/sprites/set_sheet.png");
    sfIntRect volume_rect_back;
    volume_rect_back.left = 2430; volume_rect_back.top = 550;
    volume_rect_back.height = 360; volume_rect_back.width = 1125;
    sfSprite_setPosition(tab_sprite[1], (sfVector2f){700, 400});
    sfSprite_setScale(tab_sprite[1], (sfVector2f){0.5, 0.2});
    sfSprite_setTextureRect(tab_sprite[1], volume_rect_back);
    return (init_sprite_set2(sys, tab_sprite));
}
