/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-dante-angelo.anselmet
** File description:
** main
*/

#include"include/my.h"

int check_place2(maze *maze, wait_list *wait, closed_list *closed)
{
    if (maze->j != maze->len_tab - 1 &&
    maze->tab[maze->i][maze->j + 1] == '*') {
        if (maze->nbr[1] != 3) {
            place_wait(maze, &wait, closed);
        } if (maze->nbr[1] == 3 && maze->test != maze->j + 1) {
            maze->nbr[1] = 2;
        } if (maze->nbr[1] != 1 && maze->nbr[1] != 0) {
            maze->nbr[0] = maze->j + 1; maze->nbr[1] = 1;
        } maze->test = maze->j + 1;
    } if (maze->j != 0 && maze->tab[maze->i][maze->j -  1] == '*') {
        if (maze->nbr[1] != 3) {
            place_wait(maze, &wait, closed);
        } if (maze->nbr[1] == 3 && maze->test != maze->j - 1) {
            maze->nbr[1] = 2;
        } if (maze->nbr[1] != 1 && maze->nbr[1] != 0) {
            maze->nbr[0] = maze->j - 1; maze->nbr[1] = 1;
        } maze->test = maze->j - 1;
    }
    move_tab(maze, wait, closed);
}

int check_place(maze *maze, wait_list *wait, closed_list *closed)
{
    if (maze->i != maze->len_tab - 1 &&
    maze->tab[maze->i + 1][maze->j] == '*') {
        if (maze->nbr[1] != 3) {
            place_wait(maze, &wait, closed);
        } if (maze->nbr[1] == 3 && maze->test != maze->i + 1) {
            maze->nbr[1] = 2;
        }  if (maze->nbr[1] != 0) {
            maze->nbr[0] = maze->i + 1; maze->nbr[1] = 0;
        } maze->test = maze->i + 1;
    }
    if (maze->i != 0 && maze->tab[maze->i - 1][maze->j] == '*') {
        if (maze->nbr[1] != 3) {
            place_wait(maze, &wait, closed);
        } if (maze->nbr[1] == 3 && maze->test != maze->i - 1) {
            maze->nbr[1] = 2;
        } if (maze->nbr[1] != 0) {
            maze->nbr[0] = maze->i - 1; maze->nbr[1] = 0;
        } maze->test = maze->i - 1;
    } check_place2(maze, wait, closed);
}

int back(wait_list **wait, closed_list **tmp, maze **maze_list)
{
    if ((*wait)->next != NULL) {
        (*maze_list)->last_i = (*maze_list)->i;
        (*maze_list)->last_j = (*maze_list)->j;
        (*wait) = (*wait)->next;
        (*maze_list)->i = (*wait)->i; (*maze_list)->j = (*wait)->j;
        (*maze_list)->nbr[0] = (*wait)->value;
        while ((*tmp) != NULL &&
        check_list((*maze_list), (*tmp)) != 1) {
                (*maze_list)->tab[(*tmp)->i][(*tmp)->j] = ':';
                (*tmp) = (*tmp)->next;
        }
    }
}

int fonct(maze *maze_list, wait_list *wait, closed_list *closed)
{
    maze_list->len_tab = my_strlen(maze_list->tab[0]);
    closed_list *tmp = closed;
    while (1) {
        tmp = closed;
        if (maze_list->nbr[1] == 3) {
            back(&wait, &tmp, &maze_list);
        } maze_list->nbr[1] = 3;
        insertclose(&closed, maze_list->i, maze_list->j, maze_list);
        check_place(maze_list, wait, closed);
    }
}

int main(int ac, char **av)
{
    struct stat sb;
    maze *maze_list = malloc(sizeof(maze));
    wait_list *wait = malloc(sizeof(wait_list));
    closed_list *closed = malloc(sizeof(closed_list));
    int fd = open(av[1], O_RDONLY); closed->next = NULL;
    if (fd == -1)
        return 84;
    maze_list->len_tab = 0; stat(av[1], &sb); closed->i = 0; closed->j = 0;
    char *buffer = malloc(sizeof(char) * sb.st_size + 1);
    int size = read(fd, buffer, sb.st_size); closed->prev = NULL;
    buffer[size] = '\0'; closed->next = NULL;
    maze_list->tab = my_str_to_word_array(buffer);
    int *nbr = malloc(sizeof(int) * 3); wait->value = 0;
    wait->i = 0; wait->j; maze_list->test = 0; maze_list->back = 0;
    maze_list->nbr = nbr; maze_list->i = 0; maze_list->j = 0;
    maze_list->nbr[1] = 2; maze_list->nbr[0] = 0; wait->next = NULL;
    fonct(maze_list, wait, closed);
}
