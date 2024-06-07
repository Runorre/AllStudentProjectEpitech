/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** mystrtowordarray
*/

#include "my.h"

char **my_str_to_word_array(char *str, int size)
{
    int i = 0, j = 0, e = 0;
    char **final = malloc(sizeof(char *) * (size + 1));
    final[j] = malloc(sizeof(char) * (size + 1));
    while (j != size) {
        if (i == size) {
            final[j][i] = '\0';
            j++;
            i = 0;
            final[j] = malloc(sizeof(char) * (size + 1));
        } else {
            final[j][i] = str[e];
            e++;
            i++;
        }
    }
    free(final[j]);
    final[j] = NULL;
    return final;
}

