/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** strlen
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int x = 0;
    while (str[x] != '\0') {
        x++;
    }
    return (x);
}
