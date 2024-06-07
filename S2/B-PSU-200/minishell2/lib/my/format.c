/*
** EPITECH PROJECT, 2022
** format
** File description:
** format
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int getnbr(struct Dataf *data, int *j)
{
    while (data->format[data->i] >= '0' && data->format[data->i] <= '9') {
        data->tab[(*j)] = data->format[data->i];
        data->i++;
        (*j)++;
    }
}

int jumpspace(struct Dataf *data)
{
    while (data->format[data->i] == ' ')
        data->i++;
}

int checkformat(struct Dataf *data)
{
    int j = 1;
    if (data->format[data->i] == '#')
        data->tab[j] = '#', data->i++, j++;
    jumpspace(&(*data));
    if (data->format[data->i] == '-')
        data->tab[j] = '-', data->i++, j++;
    if (data->format[data->i] == '0' && data->tab[j - 1] != '-')
        data->tab[j] = '0', data->i++, j++;
    if (data->format[data->i] == '-')
        if (data->tab[j - 1] == '0') {
            data->tab[j - 1] = '-', data->i++;
        } else if (data->tab[j - 1] != '-')
            data->tab[j] = '-', data->i++, j++;
    if (data->format[data->i] == '+')
        data->tab[j] = '+', data->i++, j++;
    return checkformat_2(&(*data), j);
}

int checkformat_2(struct Dataf *data, int j)
{
    if (data->format[data->i] >= '1' && data->format[data->i] <= '9')
        getnbr(&(*data), &j);
    if (data->format[data->i] == '.')
        data->tab[j] = '.', data->i++, j++;
    if (data->format[data->i] >= '0' && data->format[data->i] <= '9')
        getnbr(&(*data), &j);
    else if (data->tab[j - 1] == '.')
        data->tab[j] = '0', data->i++, j++;
    return 0;
}
