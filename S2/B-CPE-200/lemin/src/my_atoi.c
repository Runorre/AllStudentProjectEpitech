/*
** EPITECH PROJECT, 2023
** src/my_atoi
** File description:
** lem-in
*/
#include "../include/lem_in.h"

int my_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n'
    || c == '\r' || c == '\f' || c == '\v');
}

int my_atoi(const char *str)
{
    int result = 0, sign = 1, i = 0;

    while (my_isspace(str[i])) {
        i++;
    }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = (result * 10) + (str[i++] - '0');
    }
    return (sign * result);
}
