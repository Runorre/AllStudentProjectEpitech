/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** navy
*/
#include "../include/lem_in.h"

int number_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != '\t') &&
            (str[i + 1] == ' ' || str[i + 1] == '\t'
            || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

char **str_to_word_array(char *str)
{
    char **tab = malloc(sizeof(char*) * (number_word(str) + 1));
    int j = 0, i = 0, k = 0;

    while (str[i] != '\0') {
        tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        j = 0;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            tab[k][j] = str[i];
            i++;
            j++;
        }
        tab[k][j] = '\0';
        k++;
    }
    tab[k] = NULL;
    return (tab);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        i++;
    }
    return (0);
}

char **str_to_array(int size, FILE *fd)
{
    char **map, *buf = NULL;
    size_t size_map = 0;
    int len = 0, i = 0;
    map = malloc(sizeof(char *) * (size + 1));
    while (getline(&buf, &size_map, fd) != EOF) {
        len = my_strlen(buf);
        map[i] = malloc(sizeof(char) * (len + 1));
        my_strcpy(map[i], buf), i++;
    }
    map[size] = NULL, free(buf);
    return (map);
}
