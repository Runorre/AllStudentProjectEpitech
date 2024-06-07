/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** changemenu
*/

#include "my.h"

void actionhelpbutton(sys_data *sys)
{
    int whobutton = 1;
    for (l_button *tmp = sys->help_menu; tmp; tmp = tmp->next) {
        if (mousebutton_click(sys, tmp->select->pos_button,
        tmp->select->size_button) && whobutton == 0) {
            my_putstr("By : celestin.godefroy-mourier@epitech.eu and ");
            my_putstr("angelo.anselmet@epitech.eu\n");
        }
        if (mousebutton_click(sys, tmp->select->pos_button,
        tmp->select->size_button) && whobutton == 1) {
            my_putstr("My_Paint\nPicture editor\n");
            my_putstr("FILE : In the file menu you can save,");
            my_putstr(" open or create a new image\nEDIT: ");
            my_putstr("you have all the tools of edtition ");
            my_putstr("like the pencil or the eraser\nHELP :");
            my_putstr("Contains help information\n");
        }
        whobutton--;
    }
}

void hoverhelpbutton(sys_data *sys)
{
    for (l_button *tmp = sys->help_menu; tmp; tmp = tmp->next) {
        if (mousebutton_hover(sys, tmp->select->pos_button,
        tmp->select->size_button))
            tmp->select->state = HOVER;
        if (mousebutton_hover(sys, tmp->select->pos_button,
        tmp->select->size_button) == 0)
            tmp->select->state = NONE;
    }
}

void presshelpbutton(sys_data *sys)
{
    for (l_button *tmp = sys->help_menu; tmp;tmp = tmp->next) {
        if (mousebutton_press2(sys, tmp->select->pos_button,
        tmp->select->size_button)) {
            tmp->select->state = PRESSED;
        }
    }
}
