/*
** EPITECH PROJECT, 2023
** mouse.c
** File description:
** mouse.c
*/

#include "my.h"

int mousebutton_click(sys_data *sys, sfVector2f positon, sfVector2u size)
{
    if ((sys->mouse.x >= positon.x && sys->mouse.x <= positon.x + size.x) &&
        (sys->mouse.y >= positon.y && sys->mouse.y <= positon.y + size.y) &&
        (sys->event->type == sfEvtMouseButtonReleased)) {
            return 1;
    }
    return 0;
}

int mousebutton_hover(sys_data *sys, sfVector2f positon, sfVector2u size)
{
    if ((sys->mouse.x >= positon.x && sys->mouse.x <= positon.x + size.x) &&
        (sys->mouse.y >= positon.y && sys->mouse.y <= positon.y + size.y)) {
            return 1;
    }
    return 0;
}

int mousebutton_press2(sys_data *sys, sfVector2f positon, sfVector2u size)
{
    if ((sys->event->type == sfEvtMouseButtonPressed) == sfFalse)
        return 0;
    if ((sys->mouse.x >= positon.x && sys->mouse.x <= positon.x + size.x) &&
        (sys->mouse.y >= positon.y && sys->mouse.y <= positon.y + size.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
            return 1;
    return 0;
}

int mousebutton_press(sys_data *sys, sfVector2f positon, sfVector2u size)
{
    if ((sys->event->type == sfEvtMouseButtonReleased))
        return 0;
    if ((sys->mouse.x >= positon.x && sys->mouse.x <= positon.x + size.x) &&
    (sys->mouse.y >= positon.y && sys->mouse.y <= positon.y + size.y) &&
    (sys->event->type == sfEvtMouseButtonPressed) == sfTrue)
        return 1;
    return 2;
}
