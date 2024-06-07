/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** changemenu
*/

#include "my.h"

void actionmainbutton(sys_data *sys)
{
    int whobutton = 2;
    for (l_button *tmp = sys->but_menu; tmp; tmp = tmp->next) {
        if (mousebutton_click(sys, tmp->select->pos_button,
        tmp->select->size_button))
            sys->m_s = whobutton;
        whobutton--;
    }
}

void hovermainbutton(sys_data *sys)
{
    for (l_button *tmp = sys->but_menu; tmp; tmp = tmp->next) {
        if (mousebutton_hover(sys, tmp->select->pos_button,
        tmp->select->size_button))
            tmp->select->state = HOVER;
        if (mousebutton_hover(sys, tmp->select->pos_button,
        tmp->select->size_button) == 0)
            tmp->select->state = NONE;
    }
}

void pressmainbutton(sys_data *sys)
{
    for (l_button *tmp = sys->but_menu; tmp;tmp = tmp->next) {
        if (mousebutton_press2(sys, tmp->select->pos_button,
        tmp->select->size_button)) {
            tmp->select->state = PRESSED;
        }
    }
}
