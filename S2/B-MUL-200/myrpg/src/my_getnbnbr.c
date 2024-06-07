/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** char en int
*/

#include "rpg.h"

int transform_to_int(char *temp, bool moin, int size)
{
    int result = 0, value = 0, i = 0, y = 0;
    while (temp[i]) {
        value = temp[i] - 48;
        while (y < size - 1) {
            value *= 10;
            y++;
        }
        result += value;
        y = 0;
        size--;
        i++;
    }
    if (moin)
        return (result *= -1);
    return (result);
}

bool numerique(char c)
{
    if ((c >= '0' && c <= '9') || c == '.') {
        return (true);
    }
    return (false);
}

int malloc_size_buffer_getnbr(char *dest, int y)
{
    int compt = 0;
    if (dest[y] == '-') {
        compt++;
        y++;
    }
    while (numerique(dest[y])) {
        compt++;
        y++;
    }
    return (compt);
}

int my_getnbnbr(char *dest, int *i)
{
    int y = *i, size = malloc_size_buffer_getnbr(dest, y), t = 0;
    char *temp = malloc(sizeof(char) * size + 1);
    bool moin = false;
    if (dest[y] == '-') {
        moin = true;
        y++;
        size--;
    }
    while (numerique(dest[y])) {
        temp[t] = dest[y];
        t++;
        y++;
    }
    temp[t] = 0;
    y++;
    *i = y;
    return (transform_to_int(temp, moin, size));
}
