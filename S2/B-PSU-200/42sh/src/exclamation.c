/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** exclamation
*/

#include "sh.h"

int foundreversenbr(history *his, int where, systeme **sys)
{
    history *tmp = his->prev;
    int antineg = 1;
    while ((antineg + where) != 0 && tmp->id != 1) {
        tmp = tmp->prev;
        antineg++;
    }
    if ((antineg + where) != 0) {
        fprintf(stderr, "%i: Event not found.\n", (antineg + where));
        return 1;
    } else {
        (*sys)->buffer = strdup(tmp->command);
        fprintf(stderr, "%s", (*sys)->buffer);
        (*sys)->id = addhistory(&(*sys)->his, (*sys)->buffer, (*sys)->id);
        (*sys)->end = errorhandelingpipe(sys);
        return (*sys)->end;
    }
}

int foundnbr(history *his, int where, systeme **sys)
{
    history *tmp = his;
    while (tmp && tmp->id != where)
        tmp = tmp->next;
    if (!tmp) {
        fprintf(stderr, "%i: Event not found.\n", where);
        return 1;
    } else if (tmp->id == where) {
        (*sys)->buffer = tmp->command;
        fprintf(stderr, "%s", (*sys)->buffer);
        (*sys)->id = addhistory(&(*sys)->his, (*sys)->buffer, (*sys)->id);
        (*sys)->end = errorhandelingpipe(sys);
        return (*sys)->end;
    }
}

int exclamation(char **word, history *his, systeme **sys)
{
    if (my_strlen(word[0]) == 1)
        return my_putstrerr("!: Command not found.\n");
    char *manip = strdup(word[0]);
    int where = atoi(&manip[1]);
    if (!his) {
        fprintf(stderr, "%i: Event not found.\n", where);
        return 1;
    }
    if (where == 0 && word[0][1] == '0')
        return my_putstrerr("0: Event not found.\n");
    if (where > 0)
        return foundnbr(his, where, sys);
    if (where < 0)
        return foundreversenbr(his, where, sys);
    if (where == 0)
        return my_putstrerr("!: not implemented.\n");
}
