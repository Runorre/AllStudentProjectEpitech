/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** my_putstrstr
*/

#include "my.h"

int my_putstrstr(char **str)
{
    for (int i = 0; str[i]; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
    }
    return 0;
}
