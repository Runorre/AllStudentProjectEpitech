/*
** EPITECH PROJECT, 2021
** list
** File description:
** list
*/

#include "../include/list.h"

void insertion(Element **actuel, char *command, char *als)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    nouveau->command = command;
    nouveau->al = als;
    nouveau->suivant = NULL;
    if (!(*actuel))
        *actuel = nouveau;
    else {
        Element *tmp = *actuel;
        while (tmp->suivant)
            tmp = tmp->suivant;
        tmp->suivant = nouveau;
    }
}

void afficherliste(Element *actuel)
{
    if (actuel == NULL)
        exit(84);
    while (actuel != NULL) {
        printf("%s | ", actuel->command);
        printf("%s\n", actuel->al);
        actuel = actuel->suivant;
    }
}
