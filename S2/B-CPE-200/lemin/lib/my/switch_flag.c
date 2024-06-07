/*
** EPITECH PROJECT, 2022
** Switch
** File description:
** Switch for flag for Printf
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int modulo_type4(struct Dataf *data, va_list *ap, char *tab)
{
    switch (data->format[data->i]) {
    case 'e':
        int e = 0;
        posspace(tab, e = nota_scient(va_arg((*ap), double), 6), 1);
        negspace(tab, e);
        return data->counter += e;
    case 'n':
        return flagn(va_arg((*ap), void *), data->counter);
    case 'F':
    case 'f':
        int f = 0;
        posspace(tab, f = my_putfloat(va_arg((*ap), double), 6), 1);
        negspace(tab, e); return data->counter += f;
    case 'p':
        int p = 0;
        posspace(tab, p = exa_adress(va_arg((*ap), long unsigned int)), 0);
        negspace(tab, e); return data->counter += f;
    default:
        defaultswitch(&(*data));
    }
}

int modulo_type3(struct Dataf *data, va_list *ap)
{
    int maj = 0;
    switch (data->format[data->i]) {
    case 'S':
        int S = 0;
        posspace(data->tab, S = majs(va_arg((*ap), char*)), 0);
        negspace(data->tab, S);
        return data->counter += S;
    case 'X': maj = 1;
    case 'x':
        char *x = converter(va_arg((*ap), int), 16, maj, data->tab);
        posspace(data->tab, my_strlen(x), 1), my_putstr(x);
        negspace(data->tab, my_strlen(x));
        return data->counter += my_strlen(x);
    case '%':
        my_putchar('%');
        return data->counter++;
    default:
        return modulo_type4(&(*data), &(*ap), data->tab);
    }
}

int modulo_type2(struct Dataf *data, va_list *ap)
{
    switch (data->format[data->i]) {
    case 'b':
        char *b = converter(va_arg((*ap), int), 2, 0, data->tab);
        posspace(data->tab, my_strlen(b), 1), my_putstr(b);
        negspace(data->tab, my_strlen(b));
        return data->counter += my_strlen(b);
    case 'o':
        char *o = converter(va_arg((*ap), int), 8, 0, data->tab);
        posspace(data->tab, my_strlen(o), 1), my_putstr(o);
        negspace(data->tab, my_strlen(o));
        return data->counter += my_strlen(o);
    case 'u':
        unsigned int u = va_arg((*ap), unsigned int);
        posspace(data->tab, my_unnbrlen(u), 1), my_put_unnbr(u);
        negspace(data->tab, my_unnbrlen(u));
        return data->counter += my_unnbrlen(u);
    default:
        return modulo_type3(&(*data), &(*ap));
    }
}

int modulo_type(struct Dataf *data, va_list *ap)
{
    switch (data->format[data->i]) {
    case 'd':
    case 'i':
        int d = va_arg((*ap), int);
        pos(d, data->tab);
        posspace(data->tab, my_nbrlen(d), 1);
        my_putnbr(d);
        negspace(data->tab, my_nbrlen(d));
        return data->counter += my_nbrlen(d);
    case 's':
        char *s = va_arg((*ap), char *);
        my_putstr(s);
        return data->counter += my_strlen(s);
    case 'c':
        char c = va_arg((*ap), int);
        posspace(data->tab, 1, 0), my_putchar(c), negspace(data->tab, 1);
        return data->counter++;
    default:
        return modulo_type2(&(*data), &(*ap));
    }
}
