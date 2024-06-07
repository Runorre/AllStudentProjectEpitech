/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** dialogues
*/

#include "rpg.h"

void adjust_dial_pos(lnpc_s** npc)
{
    lnpc_s* tmp = *npc;
    sfVector2f pos;
    while (tmp != NULL) {
        if (tmp->dial->show == sfTrue) {
            pos = sfSprite_getPosition(tmp->mod->sprite);
            pos.y -= 64;
            pos.x -= 64;
            sfRectangleShape_setPosition(tmp->dial->rect, pos);
            sfText_setPosition(tmp->dial->text, pos);
        }
        tmp = tmp->next;
    }
}

void draw_dial(dial_s* dial, sfRenderWindow* win)
{
    sfRenderWindow_drawRectangleShape(win, dial->rect, NULL);
    sfRenderWindow_drawText(win, dial->text, NULL);
}

sfText *init_dtext(char *str, int scale)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setCharacterSize(text, scale);
    sfText_setPosition(text,(sfVector2f){750, 600});
    sfText_setColor(text, sfWhite);
    sfFont *font = sfFont_createFromFile("utilities/fonts/ice.ttf");
    sfText_setFont(text, font);
    return text;
}

int n_lines(char* str)
{
    int i = 0, n = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            n ++;
        i ++;
    }
    return n;
}

dial_s *create_dialogues(char *text)
{
    dial_s* dial = malloc(sizeof(dial_s));
    int x = count_until_limit(text, '\n') * 0.35;
    int n = n_lines(text);
    int y = (n == 2) ? n : n * 0.8;
    if (y == 0) y = 1;
    dial->rect = init_rect((sfVector2f){0, 0}, (sfVector2f){32 * x, 32 * y},
        sfBlack);
    dial->text = init_dtext(text, 20);
    return dial;
}
