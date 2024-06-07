/*
** EPITECH PROJECT, 2023
** mixword
** File description:
** order66
*/

#include "include.h"

void order66(data_t *data)
{
    int i = 0;
    while (data->array[i]) {
        free(data->array[i]);
        i++;
    }
    free(data->array[i]);
    free(data->array);
    i = 0;
    while (data->tab[i]) {
        free(data->tab[i]);
        i++;
    }
    free(data->tab[i]);
    free(data->tab);
    close(data->fd);
    free(data);
}
