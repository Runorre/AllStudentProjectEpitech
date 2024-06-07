/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include "../include/sh.h"

char **alloc_array(int i, int k, int j)
{
    char **tmp = malloc(sizeof(char*) * (i + k));
    while (j != (i + k)) {
        tmp[j] = malloc(sizeof(char) * (100));
        j ++;
    }
    return (tmp);
}

char **convert_alias(char **word, Element *alias)
{
    int i = 0, j = 0, k = 0;
    char **aliass = my_str_to_word_array(alias->al);
    while (aliass[k])
        k ++;
    k ++;
    while (word[i])
        i ++;
    i ++;
    char **tmp = alloc_array(i, k, j);
    i = 0, k = 0, j = 1;
    while (aliass[k]) {
        tmp[i] = strdup(aliass[k]);
        i ++; k ++;
    }
    while (word[j]) {
        tmp[i] = strdup(word[j]);
        i ++;j ++;
    }
    tmp[i] = NULL; return tmp;
}

int check_the_quote(Element *alias)
{
    int i = 0, space = 0;
    while (alias->command[i] != '\0') {
        if (alias->command[i] == ' ')
            space ++;
        i ++;
    }
    if (space > 0) {
        return (space + 1);
    }
    return (0);
}

char **check_alias(char **word, systeme **sys)
{
    int vl = 0;
    for (Element *tmp = (*sys)->alias; tmp; tmp = tmp->suivant) {
        if (my_strcmp(tmp->command, word[0])) {
            printf("%li, %s\n", sizeof(tmp->al), tmp->al);
            word = convert_alias(word, tmp);
            return word;
        }
    }
    return word;
}
