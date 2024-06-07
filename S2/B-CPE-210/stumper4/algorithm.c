/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** algorithm
*/

#include "include.h"

char **create_empty_array(data_t *data)
{
    char **array = malloc((data->size + 1) * sizeof(char *));
    array[0] = malloc((data->size + 1) * sizeof(char));
    for (int i = 0, j = 0; i < data->size; j++) {
        if (j > data->size) {
            array[i][j - 1] = '\0';
            j = 0, i++;
            array[i] = malloc((data->size + 1) * sizeof(char));
        }
        array[i][j] = 'a' + (rand() % 26);
    }
    free(array[data->size]);
    array[data->size] = NULL;
    return array;
}

int try_put_in_tab(data_t *data, int i)
{
    for (int h = 0, j = 0; data->array[h]; j++) {
        if (!data->array[h][j])
            j = 0, h++;
        if (put_right(data, j, h, i) == 1) return 1;
        if (put_down_right(data, j, h, i) == 1) return 1;
        if (put_down(data, j, h, i) == 1) return 1;
        if (put_down_left(data, j, h, i) == 1) return 1;
        if (put_left(data, j, h, i) == 1) return 1;
        if (put_up_left(data, j, h, i) == 1) return 1;
        if (put_up(data, j, h, i) == 1) return 1;
        if (put_up_right(data, j, h, i) == 1) return 1;
    }
    return 0;
}

int main_algo(data_t *data)
{
    int puting = 0;
    data->tab = create_empty_array(data);
    for (int i = 0; data->array[i]; i++) {
        puting += try_put_in_tab(data, i);
    }
    return puting;
}
