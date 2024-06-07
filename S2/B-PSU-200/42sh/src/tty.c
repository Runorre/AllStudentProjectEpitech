/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** tty
*/

#include "sh.h"

int ttymode(systeme **sys)
{
    prompt();
    signal(SIGINT, handler);
    signal(SIGTSTP, handler);
    while (getline(&(*sys)->buffer, &(*sys)->size, stdin) != -1) {
        (*sys)->id = addhistory(&(*sys)->his, (*sys)->buffer, (*sys)->id);
        (*sys)->end = errorhandelingpipe(sys);
        prompt();
    }
    my_putstr("exit\n");
    return (*sys)->end;
}
