/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** printerror
*/

#include "my.h"

void my_putstrerr(char *str)
{
    write(2, str, my_strlen(str));
}

int print_error_nofile(char *str)
{
    my_putstrerr("head: impossible d'ouvrir '");
    my_putstrerr(str);
    my_putstrerr("'\n");
    return 1;
}

int print_error_option(char c)
{
    my_putstrerr("head : option invalide -- ");
    my_putstrerr(&c);
    my_putstrerr("\n");
    return 1;
}

int print_error_num(void)
{
    my_putstrerr("head: nombre d'octets incorrect:\n");
    return 1;
}
