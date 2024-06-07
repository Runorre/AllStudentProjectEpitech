/*
** EPITECH PROJECT, 2022
** my_print_revalpha.c
** File description:
** Write in terminal the all alphabet reversed
*/

#include <unistd.h>

int my_print_revalpha(void)
{
    for (char letter = 122; letter != 96; letter--)
        write(1, &letter, 1);
}
