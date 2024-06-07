/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** my_putcharstar
*/

#include "my.h"

void my_putcharstar(char **square)
{
    for (int i = 1; square[i] != NULL; i++) {
        my_putstr(square[i]);
        my_putchar('\n');
    }
}
