/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include "../include/sh.h"

int count_quote(char **word, int i)
{
    int space = 0, j = 1, k = 0;
    while (word[i][j] != '"' && word[i] != NULL) {
        if (word[i][j] == '\0') {
            i ++;
            j = 0;
            k ++;
        } else {
            j ++;
        }
        if (word[i][j] == ' ')
            space ++;
        k ++;
    }
    return (space + 1);
}

char *stop_at_quote_tab(char **word, int i)
{
    int j = 1, k = 0;
    char *aliass = malloc(sizeof(char) * 1000);
    while (word[i][j] != '"' && word[i] != NULL) {
        if (word[i][j] == '\0') {
            i ++;
            j = 0;
            aliass[k] = ' ';
        } else {
            aliass[k] = word[i][j];
            j ++;
        }
        k ++;
    }
    aliass[k] = '\0';
    return (aliass);
}

char *conectstr(char **str, int where)
{
    int i = where;
    int j = 1, e = 0;
    char *final = malloc(sizeof(char) * 10000);
    while (str[i] && str[i][j] != '"') {
        final[e] = str[i][j];
        j++;
        if (str[i][j] == '\0') {
            i++;
            j = 0;
            e++;
            final[e] = ' ';
        }
        e++;
    }
    final[e] = '\0';
    printf("DEBUG : %s", final);
    return final;
}

int alias_b(char **word, char **env, Element **alias)
{
    int space = 0;
    char *command = "";
    char *aliass = "";
    if (word[1] == NULL || word[2 + space] == NULL)
        return (0);
    command = malloc(sizeof(char) * 10000);
    aliass = malloc(sizeof(char) * 10000);
    if (word[1][0] == '"') {
        return (0);
    } else {
        command = strdup(word[1]);
    }
    if (word[2 + space][0] == '"') {
        aliass = conectstr(word, 2 + space);
    } else {
        aliass = strdup(word[2 + space]);
    }
    insertion(alias, command, aliass);
    return (0);
}
