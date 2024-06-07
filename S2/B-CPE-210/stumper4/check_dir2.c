/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** Check_dir
*/

#include "include.h"

int put_down(data_t *data, int x, int y, int word_index)
{
    for (int i = 0; i < data->size; i++)
        if ((y + i) > data->size || data->tab[y + i][x] < 'a'
            || data->tab[y + i][x] > 'z')
            return 0;
    for (int i = 0; i < data->size; i++)
        data->tab[y + i][x] = data->array[word_index][i] - ' ';
    return 1;
}

int put_down_right(data_t *data, int x, int y, int word_index)
{
    for (int i = 0; i < data->size; i++)
        if ((y + i) > data->size || (x + i) > data->size ||
        data->tab[y + i][x + i] < 'a' || data->tab[y + i][x + i] > 'z')
            return 0;
    for (int i = 0; i < data->size; i++)
        data->tab[y + i][x + i] = data->array[word_index][i] - ' ';
    return 1;
}

int put_right(data_t *data, int x, int y, int word_index)
{
    for (int i = 0; i < data->size; i++)
        if ((x + i) > data->size || data->tab[y][x + i] < 'a'
            || data->tab[y][x + i] > 'z')
            return 0;
    for (int i = 0; i < data->size; i++)
        data->tab[y][x + i] = data->array[word_index][i] - ' ';
    return 1;
}
