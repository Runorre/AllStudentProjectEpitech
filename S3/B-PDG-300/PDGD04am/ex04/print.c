/*
** EPITECH PROJECT, 2024
** Day04AM
** File description:
** print
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str); i != 0; i--)
        printf("%c", str[i - 1]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*f_print[])() = {print_normal, print_reverse, print_upper, print_42};

    f_print[action](str);
}
