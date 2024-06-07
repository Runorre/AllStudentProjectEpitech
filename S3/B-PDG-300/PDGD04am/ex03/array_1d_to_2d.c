/*
** EPITECH PROJECT, 2024
** Day04AM
** File description:
** array_1d_to_2d
*/

#include <stddef.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int x = 0;
    int y = 0;

    (*res) = malloc(sizeof(int *) * (height + 1));
    for (int i = 0; i != height; i++)
        (*res)[i] = malloc(sizeof(int) * width);
    for (int i = 0; i != (height * width); i++) {
        if (x == width) {
            x = 0;
            y++;
        }
        (*res)[y][x] = array[i];
        x++;
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i != height; i++)
        free(array[i]);
    free(array);
}
