/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** setenv
*/

#include "my.h"

int my_strstrlen(char **str)
{
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}

int unsetenv_b(char **env, char **word)
{
    int env_i = findinstrstr(word[1], env), env_len = my_strstrlen(env);
    int dif = env_len - env_i;
    if (env_i != -1) {
        env[env_i] = NULL;
        while (dif != 0) {
            env[env_i] = env[env_i + 1];
            env_i++;
            dif--;
        }
    }
    return 0;
}

int setenv_b(char **env, char **word)
{
    int env_i = my_strstrlen(env);
    char *er = "setenv: Variable name must contain alphanumeric characters.\n";
    if (conditioncsm(word)) {
            write(2, er, 60);
            return 1;
        }
    if (my_strstrlen(word) == 1)
        return my_putstrstr(env);
    if (my_strstrlen(word) > 3) {
        my_putstrerr(word[0]);
        return my_putstrerr(": Too many arguments");
    }
    if (findinstrstr(word[1], env) != -1)
            env_i = findinstrstr(word[1], env);
    if (my_strstrlen(word) == 2)
        env[env_i] = my_strcat(word[1], "=");
    if (my_strstrlen(word) == 3)
        env[env_i] = my_strcat(my_strcat(word[1], "="), word[2]);
    env[env_i + 1] = NULL;
    return 0;
}
