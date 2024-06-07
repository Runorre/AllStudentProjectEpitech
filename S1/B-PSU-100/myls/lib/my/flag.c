/*
** EPITECH PROJECT, 2022
** flag.c
** File description:
** flag
*/

#include "my.h"

void backslash(int dual)
{
    if (dual % 2 == 0) {
        my_putchar('\\');
    }
}

char majs(const char *str)
{
    int i = 0, dual = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 127) {
            backslash(dual);
            converter_int(str[i], 8, 0);
            dual++;
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
}

char *add0(char *str)
{
    my_revstr(str);
    str[my_strlen(str)] = '0';
    my_revstr(str);
    return str;
}

int exa_adress(long unsigned int point)
{
    char *str = exa_long(point, 16, 0);
    my_putstr("0x");
    my_putstr(my_revstr(str));
    return 10;
}

int flagn(int *a, int counter)
{
    *a = counter;
    return 0;
}
