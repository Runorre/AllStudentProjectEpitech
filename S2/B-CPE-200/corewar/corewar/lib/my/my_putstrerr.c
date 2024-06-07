/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** show a string in console
*/

#include "my.h"
#include <unistd.h>

int my_putstrerr(char const *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
