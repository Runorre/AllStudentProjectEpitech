/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** unalias
*/

#include "sh.h"

void remove_from_linked_list(Element **list, char *command)
{
    Element *tmp = *list;
    Element *prev = NULL;
    if (tmp != NULL && strcmp(tmp->command, command) == 0) {
        *list = tmp->suivant;
        free(tmp);
        return;
    }
    while (tmp != NULL && strcmp(tmp->command, command) != 0) {
        prev = tmp;
        tmp = tmp->suivant;
    }
    if (tmp == NULL)
        return;
    prev->suivant = tmp->suivant;
    free(tmp);
}

int unalias_b(char **word, char **env, Element **alias)
{
    int i = 1;
    if (word[1] == NULL) {
        my_putstr("unalias: Too few arguments.\n");
        return (1);
    }
    remove_from_linked_list(alias, word[1]);
    return (0);
}
