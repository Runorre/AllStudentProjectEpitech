/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** event
*/

#include "my.h"

int events(sys_data *sys)
{
    hovermainbutton(sys);
    pressmainbutton(sys);
    actionmainbutton(sys);
    if ((sys->event->type == sfEvtKeyReleased &&
        sys->event->key.code == sfKeyEscape) ||
        sys->event->type == sfEvtClosed)
            sfRenderWindow_close(sys->window);
}

int next_loop(sys_data *sys)
{
    if (mousebutton_press(sys, sys->sprites->pos_erase,
    sys->sprites->size_erase) == 1) {
        sys->last_color = sys->pen->color_pen;
        sys->pen->color_pen = sfWhite;
    } if (mousebutton_press(sys,
    sys->canva->pos_canva, sys->canva->size_canva) != 2)
        sys->canva->mousepress = mousebutton_press(sys,
        sys->canva->pos_canva, sys->canva->size_canva);
    if (sys->canva->mousepress == 1 &&
    is_in_canva(sys, sys->canva->pos_canva,
    sys->canva->size_canva) == 1) {
        sys->canva->canva = change_canva(sys->canva,
        sfMouse_getPosition((const sfWindow *) sys->window), sys);
    } if (mousebutton_click(sys,
    sys->sprites->pos_down, sys->sprites->size_down) == 1)
        change_size_down(sys);
}

int loop_event(sys_data *sys)
{
    while (sfRenderWindow_pollEvent(sys->window, sys->event)) {
        events(sys);
        for (int i = 0; sys->button->shape[i] != NULL; i++)
            buttoninteraction(sys, sys->button->shape[i]);
        if (mousebutton_press(sys, sys->sprites->pos_pen,
        sys->sprites->size_pen) == 1)
            sys->pen->color_pen = sys->last_color;
        if (mousebutton_click(sys,
        sys->sprites->pos_up, sys->sprites->size_up) == 1)
            change_size_up(sys);
        next_loop(sys);
    }
}

void file_event(sys_data *sys)
{
    while (sfRenderWindow_pollEvent(sys->window, sys->event)) {
        events(sys);
        actionfilebutton(sys);
        hoverfilebutton(sys);
        pressfilebutton(sys);
    }
}

void help_event(sys_data *sys)
{
    while (sfRenderWindow_pollEvent(sys->window, sys->event)) {
        events(sys);
        actionhelpbutton(sys);
        hoverhelpbutton(sys);
        presshelpbutton(sys);
    }
}
