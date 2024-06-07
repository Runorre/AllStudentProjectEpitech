/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** buttons2
*/

#include "rpg.h"

button_s* reverse_buttons_list(button_s* buttons)
{
    if (buttons == NULL)
        return NULL;
    button_s* prev = NULL, *tmp = buttons, *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    buttons = prev;
    return buttons;
}
