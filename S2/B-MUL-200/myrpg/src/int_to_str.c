/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** int_to_str
*/

#include "rpg.h"

int str_to_int(char* str)
{
    int i, num;
    i = num = 0;
    while (str[i] != '\0') {
        num = num * 10 + (str[i] - '0');
        i ++;
    }
    return num;
}

int len_nb(int n)
{
    int i = 0;
    if (n == 0) {
        return (i + 1);
    }
    if (n < 0) {
        n *= -1;
        i ++;
    }
    while (n > 0) {
        n = n / 10;
        i ++;
    }
    return (i);
}

char* int_to_str(int n, char *str)
{
    int i = n / 10;
    int j = n % 10;
    int rang = len_nb(n) - 1;
    if (i != 0) {
        str = int_to_str(i, str);
    }
    str[rang] = j + '0';
    return str;
}
