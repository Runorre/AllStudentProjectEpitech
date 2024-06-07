/*
** EPITECH PROJECT, 2023
** generator
** File description:
** my_putstrstr
*/

#include "my.h"

int my_putstrstr(char **str)
{
    int end = 0;
    for (int i = 0; str[i + 1]; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
        free(str[i]);
        end = i + 1;
    }
    my_putstr(str[end]);
    free(str[end]);
    free(str);
    return 0;
}
