/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** quest
*/

#include "rpg.h"

sfText *init_text_quest(char *str, sfVector2f pos, int scale, sfColor color)
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

sfText **init_quest(void)
{
    sfText **text = malloc(sizeof(sfText *) * 4);
    text[0] = init_text_quest("Quest :",
        (sfVector2f){0, 0}, 60, sfBlack);
    text[1] = init_text_quest("Battez Sommar",
        (sfVector2f){0, 100}, 40, sfRed);
    text[2] = init_text_quest("Battez Höst",
        (sfVector2f){0, 200}, 40, sfRed);
    text[3] = init_text_quest("Battez Vinter",
        (sfVector2f){0, 300}, 40, sfRed);
    text[4] = NULL;
    return text;
}
