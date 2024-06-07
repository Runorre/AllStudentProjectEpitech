/*
** EPITECH PROJECT, 2023
** src/printing
** File description:
** lem_in
*/
#include "../include/lem_in.h"

void print_rooms(struct node *temp)
{
    my_putstr("#number_of_ants\n");
    my_putstr(temp->data), my_putstr("#rooms\n");
    temp = temp->next;
    while (temp != NULL && !find_character(temp->data, '-')) {
        if (temp->data[0] != '#')
            my_putstr(temp->data);
        if (my_strcmp(temp->data, "##start\n") == 0
        || my_strcmp(temp->data, "##end\n") == 0)
            my_putstr(temp->data);
        temp = temp->next;
    }
    my_putstr("#tunnels\n");
    while (temp != NULL) {
        if (temp->data[0] != '#')
            my_putstr(temp->data);
        temp = temp->next;
    }
    my_putstr("#moves\n");
}

void print_rooms_arr(char **arr)
{
    my_putstr("#number_of_ants\n");
    my_putstr(arr[0]), my_putstr("#rooms\n");
    int i = 1;
    while (arr[i] != NULL && !find_character(arr[i], '-')) {
        if (arr[i][0] != '#')
            my_putstr(arr[i]);
        if (my_strcmp(arr[i], "##start\n") == 0
        || my_strcmp(arr[i], "##end\n") == 0)
            my_putstr(arr[i]);
        i++;
    }
    my_putstr("#tunnels\n");
    while (arr[i] != NULL) {
        if (arr[i][0] != '#')
            my_putstr(arr[i]);
        i++;
    }
    my_putstr("#moves\n");
}
