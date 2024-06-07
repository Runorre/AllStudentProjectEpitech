/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** event
*/

#include "my.h"

int eventcondition(sys_data *sys)
{
    if (sys->event.type == sfEvtClosed)
        sfRenderWindow_close(sys->win);
    if (sys->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(sys->win);
        if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue)
            sys->show_hitbox++;
        if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
            sys->show_sp++;
    }
}

void loop_event(sys_data *sys)
{
    while (sfRenderWindow_pollEvent(sys->win, &sys->event))
        eventcondition(sys);
}
