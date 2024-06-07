/*
** EPITECH PROJECT, 2023
** modify
** File description:
** fonct for checking maze for dante
*/

#include "include/my.h"

int check_list(maze *maze, closed_list *closed)
{
    if (maze->i == closed->i && maze->j == closed->j) {
        return 1;
    } return 0;
}

void insertclose(closed_list **my_list, int i, int j, maze *maze)
{
    closed_list *new_node = malloc(sizeof(closed_list));
    new_node->prev = NULL;
    new_node->i = i;
    new_node->j = j;
    if (*my_list == NULL) {
        new_node->next = NULL;
        *my_list = new_node;
        return;
    }
    new_node->next = *my_list;
    *my_list = new_node;
}

int move_tab(maze *maze, wait_list *wait, closed_list *closed)
{
    int i = 0; maze->tab[maze->i][maze->j] = 'i';
    if (maze->i == maze->len_tab - 1 && maze->j == maze->len_tab - 1) {
        insertclose(&closed, maze->i, maze->j, maze);
        place_path(closed, maze);
        my_show_word_array(maze->tab);
        exit(0);
    } if (maze->nbr[1] == 0) {
        maze->i = maze->nbr[0];
    } if (maze->nbr[1] == 1) {
        maze->j = maze->nbr[0];
    }
}

void insertposition (int pos, maze *maze, wait_list **head)
{
    wait_list *new_node = malloc(sizeof(wait_list));
    new_node->value = maze->nbr[0];
    new_node->i = maze->i;
    new_node->j = maze->j;
    new_node->next = NULL;
    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        wait_list *temp = *head;
        while (--pos > 1) {
            temp = temp->next;
        } new_node->next = temp->next;
        temp->next = new_node;
    }
}

int place_wait(maze *maze, wait_list **wait, closed_list *closed)
{
    int test = 0; int len_closed = 0, pos = 2;
    wait_list *tmp_list = *wait;
    closed_list *tmp_closed = closed;
    if (maze->i != maze->len_tab - 1 &&
    maze->tab[maze->i + 1][maze->j] == '*') {
        test = 1; maze->nbr[0] = maze->i + 1;
    } if (maze->i != 0 && maze->tab[maze->i - 1][maze->j] == '*' && test == 0) {
        maze->nbr[0] = maze->i - 1; test = 1;
    } if (maze->j != maze->len_tab - 1 &&
    maze->tab[maze->i][maze->j + 1] == '*' && test == 0) {
        maze->nbr[0] = maze->j + 1; test = 1;
    } if (maze->j != 0 && maze->tab[maze->i][maze->j - 1] == '*' && test == 0) {
        maze->nbr[0] = maze->j - 1;
    }
    while (tmp_list->next != NULL && tmp_list->value >= maze->nbr[0]) {
        pos++;
        tmp_list = tmp_list->next;
    }
    insertposition(2, maze, wait);
}
