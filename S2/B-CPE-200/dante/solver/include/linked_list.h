/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** linked_list
*/

#ifndef linked_list
    #define linked_list

typedef struct wait_list {
    int i;
    int j;
    int value;
    struct wait_list *next;
} wait_list;

typedef struct closed_list {
    int i;
    int j;
    struct closed_list *prev;
    struct closed_list *next;
} closed_list;




#endif /* !linked_list */
