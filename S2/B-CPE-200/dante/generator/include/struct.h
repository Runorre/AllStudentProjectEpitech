/*
** EPITECH PROJECT, 2023
** generator
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct linked_list {
        struct linked_list *prev;
        int x;
        int y;
        struct linked_list *next;
    }list;

    typedef struct position {
        int x;
        int y;
    }position;
#endif /* !STRUCT_H_ */
