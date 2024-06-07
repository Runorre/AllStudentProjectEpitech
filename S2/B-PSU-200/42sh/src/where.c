/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** where
*/

#include "../include/sh.h"

int is_a_builtin(char **arg, int e)
{
    if (my_strcmp("where", arg[e]) || my_strcmp("which", arg[e])
    || my_strcmp("setenv", arg[e]) || my_strcmp("unsetenv", arg[e])
    || my_strcmp("cd", arg[e]) || my_strcmp("env", arg[e])
    || my_strcmp("exit", arg[e]) || my_strcmp("echo", arg[e])) {
        my_putstr(arg[e]);
        my_putstr(" is a shell built-in\n");
        return 0;
    } else {
        return 1;
    }
}

int where_function(char **arg, char **env)
{
    int i = 1, e = 1;
    int path = findinstrstr("PATH=", env);
    char **allpath = my_str_to_word_array2(getinfopwd(env, path), ':');
    while (i != my_array_len(arg)){
        is_a_builtin(arg, i);
        where_function2(arg, allpath, e);
        i ++; e ++;
    }
    return 0;
}

int where_function2(char **arg, char **allpath, int e)
{
    for (int i = 0; allpath[i]; i++) {
        if (access(my_strcat(allpath[i], my_strcat("/", arg[e])), X_OK) == 0) {
            my_putstr(my_strcat(allpath[i], my_strcat("/", arg[e])));
            my_putchar('\n');
        }
    }
}

int my_array_len(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i ++;
    }
    return i;
}
