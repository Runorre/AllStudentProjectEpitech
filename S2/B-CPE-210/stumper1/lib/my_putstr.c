/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** str
*/

#include "../include/my.h"

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
