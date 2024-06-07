/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** str_related
*/

#include "./include.h"

int my_array_len(char **array)
{
    int i = 0;
    for (; array[i]; i++);
    return i;
}
