/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** show
*/

#include "my.h"

void editmenu(sys_data *sys)
{
    sfRenderWindow_drawRectangleShape(sys->window, sys->button->shape[0],
    NULL);
    sfRenderWindow_drawSprite(sys->window, sys->sprites->pen, NULL);
    sfRenderWindow_drawSprite(sys->window, sys->sprites->eraser, NULL);
    sfRenderWindow_drawSprite(sys->window, sys->sprites->up, NULL);
    sfRenderWindow_drawSprite(sys->window, sys->sprites->down, NULL);
    sfRenderWindow_drawText(sys->window, sys->pen->text_size, NULL);
    for (int i = 0; sys->button->shape[i] != NULL; i++)
        sfRenderWindow_drawRectangleShape(sys->window,
        sys->button->shape[i], NULL);
}

void showmainbutton(sys_data *sys)
{
    for (l_button *tmp = sys->but_menu; tmp; tmp = tmp->next) {
        sfRenderWindow_drawText(sys->window, tmp->select->txt, NULL);
        sfRenderWindow_drawRectangleShape(sys->window, tmp->select->shape,
        NULL);
    }
}

void showfilebutton(sys_data *sys)
{
    for (l_button *tmp = sys->file_menu; tmp; tmp = tmp->next) {
        sfRenderWindow_drawText(sys->window, tmp->select->txt, NULL);
        sfRenderWindow_drawRectangleShape(sys->window, tmp->select->shape,
        NULL);
    }
}

void showhelpbutton(sys_data *sys)
{
    for (l_button *tmp = sys->help_menu; tmp; tmp = tmp->next) {
        sfRenderWindow_drawText(sys->window, tmp->select->txt, NULL);
        sfRenderWindow_drawRectangleShape(sys->window, tmp->select->shape,
        NULL);
    }
}
