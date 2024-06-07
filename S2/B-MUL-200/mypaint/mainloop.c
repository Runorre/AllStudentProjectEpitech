/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** mainloop
*/

#include "my.h"

void buttoninteraction(sys_data *sys, sfRectangleShape *button)
{
    sys->tmp = sfRectangleShape_getPosition(button);
    if (mousebutton_click(sys, sys->tmp,
    sys->button->size_button)) {
        sys->last_color = sys->pen->color_pen;
        sys->pen->color_pen = sfRectangleShape_getFillColor(button);
    }
}

int inter_loop(sys_data *sys, sfColor sfGrey)
{
    sys->mouse = sfMouse_getPosition((const sfWindow *)sys->window);
    sfRenderWindow_display(sys->window);
    sfRenderWindow_clear(sys->window, sfGrey);
    showmainbutton(sys);
    animehover(sys);
    animepress(sys);
    sfRenderWindow_drawSprite(sys->window, sys->canva->canva, NULL);
    if (sys->m_s == EDIT) {
        editmenu(sys);
        loop_event(sys);
    }
    if (sys->m_s == FILEMENU) {
        showfilebutton(sys);
        file_event(sys);
    }
    if (sys->m_s == HELP) {
        showhelpbutton(sys);
        help_event(sys);
    }
}
