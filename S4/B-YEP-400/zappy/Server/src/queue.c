/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** queue
*/

#include "../include/server.h"

int remove_first_node(linked_queue_t **list)
{
    linked_queue_t *next_node = NULL;

    if (!*list)
        return 84;
    next_node = (*list)->next;
    free((*list)->queue->agrs);
    free((*list)->queue);
    *list = next_node;
    return 0;
}

int add_in_list_queue(linked_queue_t **list, linked_queue_t *new)
{
    linked_queue_t *tmp = NULL;

    if (!new)
        return 84;
    if (!*list) {
        *list = new;
        return 0;
    }
    for (tmp = *list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return 0;
}

linked_queue_t *add_node_queue(char *a, int t, action_function_t f)
{
    linked_queue_t *new = malloc(sizeof(linked_queue_t));

    new->queue = malloc(sizeof(queue_t));
    new->queue->time_left = t;
    new->queue->agrs = a;
    new->queue->action = f;
    new->next = NULL;
    return new;
}
