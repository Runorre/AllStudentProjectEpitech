/*
** EPITECH PROJECT, 2022
** printf
** File description:
** code a printf
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"
#include <stdlib.h>

int checkiflong(struct Dataf *data, va_list *ap)
{
    if (data->format[data->i] == 'l') {
        data->i++;
        return modulo_type_l(&(*data), &(*ap));
    } else {
        modulo_type(&(*data), &(*ap));
    }
}

int condition(struct Dataf *data , va_list *ap)
{
    int space = 0; data->tab = malloc(sizeof(char) * 100);
    if (data->format[data->i] == '%') {
        data->tab[0] = '%';
        data->i++;
        while (data->format[data->i] == ' ')
            space = 1, data->i++;
        checkformat(&(*data));
        if (data->format[data->i] == '\0')
            return data->counter = -1;
        if ((data->format[data->i] == 'd' || data->format[data->i] == 'i')
            && space == 1)
            my_putchar(' '), data->counter++;
        return (checkiflong(&(*data), &(*ap)));
    } else {
        my_putchar(data->format[data->i]);
        return data->counter++;
    }
}

int my_printf(const char *format, ...)
{
    struct Dataf data;
    va_list ap;
    va_start(ap, format);
    data.counter = 0;
    data.format = format;
    for (data.i = 0; data.format[data.i] != '\0'
        && data.counter != -1; data.i++) {
        if (data.format[data.i] == '\\' && data.format[data.i + 1] == 'n') {
            my_putchar('\n');
            data.i++;
            data.counter++;
        } else {
            condition(&data, &ap);
        }
    }
    va_end(ap);
    return data.counter;
}
