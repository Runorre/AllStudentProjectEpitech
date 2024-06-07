/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** echo function
*/

#include "sh.h"

int echo_dollar(char **word, char **env, int i, int last)
{
    if (word[i][1] == '?') {
        my_put_nbr(last);
        return (0);
    }
    if (findinstrstr(word[i] + 1, env) == -1) {
        my_putstr(word[i]);
        my_putstr(": Undefined variable.");
        return (1);
    }
    my_putstr(getinfopwd(env, findinstrstr(word[i] + 1, env)));
    return (0);
}

int echo_working(char **word, char **env, int last)
{
    int i = 1;
    while (word[i + 1] != NULL) {
        if (word[i][0] == '$' && word[i][1] != '\0') {
            echo_dollar(word, env, i, last);
            my_putchar(' ');
        } else {
            my_putstr(word[i]);
            my_putchar(' ');
        }
        i++;
    }
    if (word[i][0] == '$' && word[i][1] != '\0') {
        echo_dollar(word, env, i, last);
    } else {
        my_putstr(word[i]);
    }
}

int echo_b(char **word,  char **env, int last)
{
    int i = 1;
    if (word[1] == NULL) {
        my_putchar('\n');
        return (0);
    }
    echo_working(word, env, last);
    my_putchar('\n');
    return (0);
}
