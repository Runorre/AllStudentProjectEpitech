/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** signal
*/

#include "my.h"

void handler(int signal)
{
    if (signal == SIGINT) {
        my_putstr("\n$>");
    }
}
