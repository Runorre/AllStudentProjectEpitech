/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** history
*/

#include "sh.h"

int addhistory(history **his, char *command, int id)
{
    if (my_strstartwith("!", command) || command[0] == '\n')
        return id;
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    history *new = malloc(sizeof(history));
    new->id = id;
    new->prev = new;
    new->hour = tm_struct->tm_hour;
    new->minute = tm_struct->tm_min;
    new->command = strdup(command);
    new->next = NULL;
    if (!(*his))
        *his = new;
    else {
        history *tmp = (*his)->prev;
        tmp->next = new;
        new->prev = tmp;
        (*his)->prev = new;
    }
    return id + 1;
}

int checknum(char *word)
{
    for (int i = 0; word[i] != '\0'; i++) {
        if (!((word[i] >= '0' && word[i] <= '9'))) {
            return 1;
        }
    }
    return 0;
}

int command_history(char **word, history *his)
{
    if (my_strstrlen(word) == 1)
        return showhistory(his);
    if (checknum(word[1]))
        return my_putstrerr("history: Badly formed number.\n");
    int number = atoi(word[1]);
    if (number < 0) {
        my_putstrerr("Usage: history");
        return my_putstrerr(" [-chrSLMT] [# number of events].\n");
    }
    history *tmp = his->prev;
    for (int i = 1; i != number && tmp->id != 1; i++)
        tmp = tmp->prev;
    showhistory(tmp);
    return 0;
}

int showhistory(history *his)
{
    for (history *tmp = his; tmp; tmp = tmp->next) {
        for (int i = 5 - my_nbrlen(tmp->id); i > 0; i--)
            my_putchar(' ');
        printf("%i  %i:%i   %s",
        tmp->id, tmp->hour, tmp->minute, tmp->command);
        if (tmp->command[my_strlen(tmp->command) - 1] != '\n')
            my_putchar('\n');
    }
}
