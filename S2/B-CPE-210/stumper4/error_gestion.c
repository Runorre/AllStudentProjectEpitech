/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** Error gestion
*/

#include "./include.h"

int i_love_banana(char *str, data_t *data, int r_value)
{
    if (r_value == 84)
        return 84;
    if (strlen(str) > data->size)
        return 84;
    return 0;
}

int error_gestion(data_t *data)
{
    int r_value = 0;
    for (int i = 0, j = 0; data->array[i]; j++) {
        if ((data->array[i][j] < 'a' || data->array[i][j] > 'z')
            && data->array[i][j] != '\0')
            return 84;
        if (!data->array[i][j]) {
            r_value = i_love_banana(data->array[i], data, r_value);
            j = 0, i++;
        }
    }
    return r_value;
}
