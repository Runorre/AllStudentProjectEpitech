/*
** EPITECH PROJECT, 2023
** src/linked
** File description:
** utils for linked list
*/
#include "../include/lem_in.h"

void delete_list(struct node *head)
{
    struct node *current = head, *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

list_t *new_node(char *data)
{
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void append(struct node **head, char *data)
{
    struct node *node = new_node(data);
    struct node *last = *head;
    if (*head == NULL) {
        *head = node;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = node;
    node->prev = last;
}

void delete_node(struct node **head, struct node *del)
{
    if (*head == NULL || del == NULL)
        return;
    if (*head == del)
        *head = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}

void print_list(struct node *temp)
{
    while (temp != NULL) {
        my_putstr(temp->data);
        temp = temp->next;
    }
}
