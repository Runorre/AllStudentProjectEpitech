/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** buttons
*/

#include "rpg.h"

button_s* init_button(char* str, char* file, sfVector2f pos, sfVector2f size)
{
    button_s* button = malloc(sizeof(button_s));
    button->rect = sfRectangleShape_create();
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    rect->left = 0, rect->top = 0, rect->width = 1690 / 2, rect->height = 272;
    sfTexture* texture = sfTexture_createFromFile(file, rect);
    sfFont* font = sfFont_createFromFile("./utilities/fonts/ice.ttf");
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, texture, sfTrue);
    button->status = IDLE;
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 24);
    pos.x += size.x / 5; pos.y += size.y / 3;
    sfText_setPosition(button->text, pos);
    sfText_setString(button->text, str);
    sfText_setFont(button->text, font);
    sfText_setColor(button->text, sfBlack);
    button->next = NULL;
    button->file = file;
    return button;
}

button_s* add_button(button_s* head, button_s* button)
{
    if (head == NULL) {
        button->next = NULL;
        return button;
    }
    button->next = head;
    return button;
}

button_s* init_buttons_list(char** tab, char* file,
    sfVector2f pos, sfVector2f size)
{
    button_s* buttons = NULL;
    button_s* tmp;
    int i = 0;
    while (tab[i] != NULL) {
        buttons = add_button(buttons, init_button(tab[i], file, pos, size));
        pos.y += size.y * 1.25;
        i ++;
    }
    return reverse_buttons_list(buttons);
}

void display_buttons(sfRenderWindow* window, button_s* buttons)
{
    button_s* tmp = buttons;
    while (tmp != NULL) {
        sfRenderWindow_drawRectangleShape(window, tmp->rect, NULL);
        sfRenderWindow_drawText(window, tmp->text, NULL);
        tmp = tmp->next;
    }
}

void adapt_buttons_menu(button_s** buttons, int choice)
{
    int i = 0;
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    sfTexture* texture;
    button_s* tmp = *buttons;
    rect->top = 0, rect->width = 1690 / 2, rect->height = 272;
    while (tmp != NULL) {
        if (i == choice) {
            tmp->status == HOVER;
            rect->left = rect->width;
        } else {
            tmp->status == IDLE;
            rect->left = 0;
        }
        texture = sfTexture_createFromFile(tmp->file, rect);
        sfRectangleShape_setTexture(tmp->rect, texture, sfTrue);
        tmp = tmp->next;
        i ++;
    }
}
