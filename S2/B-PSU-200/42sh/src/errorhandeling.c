/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell2-angelo.anselmet
** File description:
** pipe
*/

#include "sh.h"

int checkerror_r(char **par, int i)
{
    if (!(my_strcmp(par[i], ">")))
        return 0;
    if (i == 0) {
        my_putstrerr("Invalid null command.\n");
        return 1;
    }
    if (par[i + 1] == NULL || my_strcmp(par[i + 1], ";") ||
    my_strcmp(par[i + 1], "|")) {
        my_putstrerr("Missing name for redirect.\n");
        return 1;
    }
    if (par[i + 2] != NULL && (my_strcmp(par[i + 2], "|"))) {
        my_putstrerr("Ambiguous output redirect.\n");
        return 1;
    }
    if ((my_strcmp(par[i + 1], ">") || my_strcmp(par[i + 1], ">>"))) {
        my_putstrerr("Ambiguous output redirect.\n");
        return 1;
    }
    return 0;
}

int checkerror_p(char **par, int i)
{
    if (!(my_strcmp(par[i], "|")))
        return 0;
    if (i == 0) {
        my_putstrerr("Invalid null command.\n");
        return 1;
    }
    if (par[i + 1] == NULL || my_strcmp(par[i + 1], ";") ||
    my_strcmp(par[i + 1], ">"))
        return my_putstrerr("Invalid null command.\n");
    if (my_strcmp(par[i - 1], ";") ||
    my_strcmp(par[i - 1], ">")) {
        my_putstrerr("Invalid null command.\n");
        return 1;
    }
    if (i >= 2 && (my_strcmp(par[i - 2], ";") ||
    my_strcmp(par[i - 2], ">"))) {
        my_putstrerr("Invalid null command.\n");
        return 1;
    }
    return 0;
}

int errorhandelingpipe(systeme **sys)
{
    if ((*sys)->buffer[0] == '\n')
        return 0;
    int i = 0;
    char **parsing = my_str_to_word_array((*sys)->buffer);
    for (i; parsing[i]; i++) {
        if (checkerror_r(parsing, i) || checkerror_p(parsing, i))
            return 1;
    }
    order66(parsing);
    return checkmultycommand(sys);
}
