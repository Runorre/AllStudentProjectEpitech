/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    typedef struct Element_d {
        char *command;
        char *al;
        struct Element_d *suivant;
    }Element;

    void suppression(Element *Element, char *nom);
    void afficherElement(Element *Element);

#endif /* !LIST_H_ */
