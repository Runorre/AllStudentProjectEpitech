/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display fonct for struct
*/

#include "include/my.h"

void display (closed_list *node)
{
    closed_list *tmp = node;
    my_putstr("Linked List : ");
    while (tmp != NULL) {
        my_put_nbr(tmp->i); my_put_nbr(tmp->i);
        my_putchar('\n');
        tmp = tmp->next;
    } printf ("\n");
}

void display_wait (wait_list *node)
{
    wait_list *tmp = node;
    my_putstr("Linked List : ");
    while (tmp != NULL) {
        my_put_nbr(tmp->i); my_put_nbr(tmp->i);
        my_putchar('\n');
        tmp = tmp->next;
    } printf ("\n");
}

int place_path(closed_list *closed, maze *maze)
{
    while (closed != NULL) {
        if (maze->tab[closed->i][closed->j] != ':')
            maze->tab[closed->i][closed->j] = 'o';
        closed = closed->next;
    }
    for (int i = 0, j = 0; maze->tab[i] != NULL; j++) {
        if (maze->tab[i][j] == 'i' || maze->tab[i][j] == ':')
            maze->tab[i][j] = '*';
        if (maze->tab[i][j] == '\0') {
            i++;
            j = -1;
        }
    }
}
