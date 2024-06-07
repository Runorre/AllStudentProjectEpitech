/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** cd
*/

#include "sh.h"

char *getinfopwd(char **env, int line)
{
    int i = 0, j = 0;
    char *final = malloc(sizeof(char) * (my_strlen(env[line])));
    while (env[line][j] != '=')
        j++;
    j++;
    while (env[line][j] != '\0') {
        final[i] = env[line][j];
        i++;
        j++;
    }
    final[i] = '\0';
    return final;
}

int nooldpwd(char **env)
{
    int env_i = my_strstrlen(env);
    env[env_i] = my_strcat("OLDPWD=", getcwd(NULL, 0));
    env[env_i + 1] = NULL;
    return env_i;
}

int changedir(char **arg, char **env)
{
    int pwd = findinstrstr("PWD=", env), old = findinstrstr("OLDPWD=", env);
    if (old == -1)
        old = nooldpwd(env);
    int home = findinstrstr("HOME=", env), execute = 0;
    if (my_strstrlen(arg) == 1 || my_strcmp("~", arg[1])) {
        chdir(getinfopwd(env, home));
        execute++;
    }
    if (execute == 0 && my_strcmp("-", arg[1])) {
        chdir(getinfopwd(env, old));
        env[pwd] = my_strcat("PWD=", getcwd(NULL, 0));
        return 0;
    }
    if (execute == 0 && chdir(arg[1]) == -1)
        return printerror(arg[1]);
    env[old] = my_strcat("OLDPWD=", getinfopwd(env, pwd));
    env[pwd] = my_strcat("PWD=", getcwd(NULL, 0));
    return 0;
}
