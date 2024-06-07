/*
** EPITECH PROJECT, 2022
** Switch
** File description:
** Switch for flag for Printf (long ver)
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int modulo_type4_l(struct Dataf *data, va_list *ap)
{
    switch (data->format[data->i]) {
    case 'n':
        return flagn(va_arg((*ap), void *), data->counter);
    case 'F':
    case 'f':
        return my_putfloat(va_arg((*ap), double), 6);
    case 'p':
        return data->counter += exa_adress(va_arg((*ap), long unsigned int));
    default:
        my_putstr(data->tab);
        my_putchar(data->format[data->i]);
        return data->counter += 1 + my_strlen(data->tab);
    }
}

int modulo_type3_l(struct Dataf *data, va_list *ap)
{
    int maj = 0;
    switch (data->format[data->i]) {
    case 'S':
        return -1;
    case 'X': maj = 1;
    case 'x':
        char *x = converter_long(va_arg((*ap), long), 16, maj);
        my_putstr(x);
        return data->counter += my_strlen(x);
    case '%':
        my_putchar('%');
        return data->counter++;
    default:
        return modulo_type4_l(&(*data), &(*ap));
    }
}

int modulo_type2_l(struct Dataf *data, va_list *ap)
{
    switch (data->format[data->i]) {
    case 'b':
        char *b = converter_long(va_arg((*ap), long), 2, 0);
        my_putstr(b);
        return data->counter += my_strlen(b);
    case 'o':
        char *o = converter_long(va_arg((*ap), long), 8, 0);
        my_putstr(o);
        return data->counter += my_strlen(o);
    case 'u':
        unsigned long u = va_arg((*ap), unsigned long);
        my_put_unlongnbr(u);
        return data->counter += my_unlongnbrlen(u);
    default:
        return modulo_type3_l(&(*data), &(*ap));
    }
}

int modulo_type_l(struct Dataf *data, va_list *ap)
{
    switch (data->format[data->i]) {
    case 'd':
    case 'i':
        long d = va_arg((*ap), long);
        my_put_longnbr(d);
        return data->counter += my_longnbrlen(d);
    case 's':
        return data->counter = -1;
    case 'c':
        char c = va_arg((*ap), int);
        my_putchar(c);
        return data->counter++;
    default:
        return modulo_type2_l(&(*data), &(*ap));
    }
}
