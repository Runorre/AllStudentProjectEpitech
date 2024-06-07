/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** initmenu
*/

#include "my.h"

l_button *addbutton(l_button *list, char *text, sfVector2f pos)
{
    l_button *new = malloc(sizeof(l_button));
    new->select = malloc(sizeof(but));
    new->select->pos_button = pos;
    new->select->txt = init_text(pos, 25, text);
    new->select->size_button = (sfVector2u) {60, 40};
    new->select->shape = sfRectangleShape_create();
    new->select->state = NONE;
    sfRectangleShape_setSize(new->select->shape, (sfVector2f) {60, 40});
    sfRectangleShape_setPosition(new->select->shape, pos);
    sfRectangleShape_setFillColor(new->select->shape, sfTransparent);
    sfRectangleShape_setOutlineColor(new->select->shape, sfTransparent);
    new->next = list;
    return new;
}

void initmenu(sys_data *sys)
{
    sys->but_menu = addbutton(NULL, "FILE", (sfVector2f) {25, 25});
    sys->but_menu = addbutton(sys->but_menu, "EDIT", (sfVector2f) {100, 25});
    sys->but_menu = addbutton(sys->but_menu, "HELP", (sfVector2f) {175, 25});
    sys->file_menu = addbutton(NULL, "NEW", (sfVector2f) {25, 100});
    sys->file_menu = addbutton(sys->file_menu, "OPEN", (sfVector2f) {125, 100});
    sys->file_menu = addbutton(sys->file_menu, "SAVE", (sfVector2f) {225, 100});
    sys->help_menu = addbutton(NULL, "ABOUT", (sfVector2f) {25, 100});
    sys->help_menu = addbutton(sys->help_menu, "HELP", (sfVector2f) {125, 100});
}
