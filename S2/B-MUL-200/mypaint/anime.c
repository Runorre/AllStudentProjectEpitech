/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** anime
*/

#include "my.h"

void animehover(sys_data *sys)
{
    for (l_button *tmp = sys->but_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == HOVER)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_hover);
        if (tmp->select->state == NONE) {
            sfRectangleShape_setFillColor(tmp->select->shape, sfTransparent);
        }
    }
    for (l_button *tmp = sys->file_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == HOVER)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_hover);
        if (tmp->select->state == NONE) {
            sfRectangleShape_setFillColor(tmp->select->shape, sfTransparent);
        }
    }
    for (l_button *tmp = sys->help_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == HOVER)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_hover);
        if (tmp->select->state == NONE)
            sfRectangleShape_setFillColor(tmp->select->shape, sfTransparent);
    }
}

void animepress(sys_data *sys)
{
    for (l_button *tmp = sys->but_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == PRESSED)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_press);
    }
    for (l_button *tmp = sys->file_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == PRESSED)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_press);
    }
    for (l_button *tmp = sys->help_menu; tmp; tmp = tmp->next) {
        if (tmp->select->state == PRESSED)
            sfRectangleShape_setFillColor(tmp->select->shape, sys->c_press);
    }
}
