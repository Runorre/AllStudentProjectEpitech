/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** action
*/

#include "my.h"

char *swap_elem(struct node *list, int who)
{
    int tmp = list->next->value;
    list->next->value = list->value;
    list->value = tmp;
    if (who == 1)
        return "sa";
    else
        return "sb";
}

char *rotate_left(struct node **list, int who)
{
    struct node *nn = *list;
    int tmp = nn->value;
    while (nn->next != NULL) {
        nn->value = nn->next->value;
        nn = nn->next;
    }
    nn->value = tmp;
    if (who == 1)
        return "ra";
    else if (who == 0)
        return "rb";
}

char *rotate_right(struct node **list, int who)
{
    struct node *nn = (*list)->next;
    while (nn->next != NULL) {
        nn = nn->next;
    }
    int tmp = nn->value;
    nn = nn->prev;
    while (nn->prev != NULL) {
        nn->next->value = nn->value;
        nn = nn->prev;
    }
    nn->next->value = nn->value;
    nn->value = tmp;
    if (who == 1)
        return "rra";
    else if (who == 0)
        return "rrb";
}

char *swap_list(struct node **list_a, struct node **list_b, int who)
{
    int tmp = (*list_a)->value;
    *list_b = addnode_2(*list_b, tmp);
    *list_a = (*list_a)->next;
    if ((*list_a) != NULL)
        (*list_a)->prev = NULL;
    if (who == 1)
        return "pa";
    else if (who == 0)
        return "pb";
}
