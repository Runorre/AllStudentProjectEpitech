/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** int_to_str
*/

#include "rpg.h"

char* putnbr(int num)
{
    int temp = num;
    int length = 0;
    while (temp > 0) {
        temp /= 10;
        length++;
    }
    char* str = malloc(length + 1);
    str[length] = '\0';
    for (int i = length - 1; i >= 0; i--) {
        str[i] = num % 10 + '0';
        num /= 10;
    }
    if (my_strlen(str) == 0)
        return "0";
    return str;
}
