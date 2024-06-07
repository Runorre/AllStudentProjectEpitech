/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** code a printf simplifed
*/

#include <stdarg.h>

int my_nbrlen(int n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

int modulo_type2(const char *format, int i)
{
    switch (format[i]) {
    case '%':
        my_putchar('%');
        return 1;
    default:
        my_putchar('%');
        my_putchar(format[i]);
        return 2;
    }
}

int modulo_type(const char *format, va_list *ap, int i)
{
    switch (format[i]) {
    case 'd':
    case 'i':
        int d = va_arg((*ap), int);
        my_put_nbr(d);
        return my_nbrlen(d);
    case 's':
        char *s = va_arg((*ap), char *);
        my_putstr(s);
        return my_strlen(s);
    case 'c':
        char c = va_arg((*ap), char *);
        my_putchar(c);
        return 1;
    default:
        return modulo_type2(format, i);
    }
}

int condition(const char *format, va_list *ap, int *i, int counter)
{
    int space = 0;
    if (format[(*i)] == '%') {
        (*i)++;
        while (format[(*i)] == ' ') {
            space = 1;
            (*i)++;
        }
        if (format[(*i)] == '\0')
            return -1;
        if ((format[(*i)] == 'd' || format[(*i)] == 'i') && space == 1) {
            my_putchar(' ');
            counter++;
        }
        return (counter + modulo_type(format, &(*ap), (*i)));
    } else {
        my_putchar(format[(*i)]);
        return (counter + 1);
    }
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int counter = 0;
    for (int i = 0; format[i] != '\0' && counter != -1; i++) {
        if (format[i] == '\\' && format[i + 1] == 'n') {
            my_putchar('\n');
            i++;
            counter++;
        } else
            counter = condition(format, &ap, &i, counter);
    }
    va_end(ap);
    return counter;
}
