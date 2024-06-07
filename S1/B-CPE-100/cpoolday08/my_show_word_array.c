/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** 
*/

#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    int len = 0;
    for (int i = 0; tab[i] != 0; i++) {
        len = my_strlen(tab[i]) + 2;
        char *str = malloc(sizeof(char) * len);
        int e = 0;
        while (tab[i][e] != '\0') {
            str[e] = tab[i][e];
            e++;
        }
        str[e] = '\n';
        str[e + 1] = '\0';
        my_putstr(str);
        free(str);
    }
}
