/*
** EPITECH PROJECT, 2023
** putstr
** File description:
** putstr
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void checkword(char *str)
{
    int len = my_strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

