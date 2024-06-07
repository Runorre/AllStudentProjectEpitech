/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** error
*/

#include "my.h"

int checkword(char *str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    if (my_strlen(str) == 1 && i == 1)
        return 1;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

int checkargu(char **av, int ac)
{
    for (int i = 1; i != ac; i++) {
        if (checkword(av[i]) == 1)
            return 84;
    }
    return 0;
}

int checkcomplete(struct node *list)
{
    if (list->next == NULL) {
        return 1;
    }
    struct node *tmp;
    tmp = list->next;
    int i = 0;
    while (tmp->next != NULL) {
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
