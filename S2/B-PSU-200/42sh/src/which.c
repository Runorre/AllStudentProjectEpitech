/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** which
*/

#include "../include/sh.h"

int which_function(char **arg, char **env)
{
    int built = 0, i = 1, e = 1;
    int path = findinstrstr("PATH=", env);
    char **allpath = my_str_to_word_array2(getinfopwd(env, path), ':');
    while (i != my_array_len(arg)){
        built = is_a_builtin(arg, i);
        if (built == 1){
            which_function2(arg, allpath, e);
        }
        i ++; e ++;
    }
    return 0;
}

int which_function2(char **arg, char **allpath, int e)
{
    int z = 0;
    for (int i = 0; allpath[i]; i++) {
        if (access(my_strcat(allpath[i], my_strcat("/", arg[e])), X_OK) == 0) {
            my_putstr(my_strcat(allpath[i], my_strcat("/", arg[e])));
            my_putchar('\n'); z ++;
            break;
        }
    }
    if (z == 0){
        my_putstr(arg[1]); my_putstr(": Command not found.\n");
    }
}
