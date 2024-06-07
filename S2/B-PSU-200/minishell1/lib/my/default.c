/*
** EPITECH PROJECT, 2022
** deflaut
** File description:
** default switch
*/

#include "my.h"
#include "struct.h"

int defaultswitch(struct Dataf *data)
{
    my_putstr(data->tab);
    my_putchar(data->format[data->i]);
    return data->counter += 1 + my_strlen(data->tab);
}
