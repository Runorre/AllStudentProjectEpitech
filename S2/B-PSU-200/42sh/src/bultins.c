/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** bultins
*/

#include "sh.h"

int terminal_main2(char **word, systeme **sys)
{
    if (my_strcmp("alias", word[0]))
        return alias_b(word, (*sys)->env, &(*sys)->alias);
    if (my_strcmp("unalias", word[0]))
        return unalias_b(word, (*sys)->env, &(*sys)->alias);
    if (my_strcmp("echo", word[0]))
        return echo_b(word, (*sys)->env, (*sys)->end);
    if (my_strcmp("where", word[0]))
        return where_function(word, (*sys)->env);
    if (my_strcmp("which", word[0]))
        return which_function(word, (*sys)->env);
    if (my_strcmp("history", word[0]))
        return command_history(word, (*sys)->his);
    if (my_strstartwith("!", word[0]))
        return exclamation(word, (*sys)->his, sys);
    if (my_strstartwith("./", word[0]) || my_strstartwith("/", word[0]))
        return checkingexcute(word, (*sys)->env);
    else if (!(my_strcmp("", word[0])))
        return command_existe((*sys)->env, word);
    return 0;
}
