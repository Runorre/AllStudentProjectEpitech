/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** show a string in console
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
