/*
** EPITECH PROJECT, 2023
** test/sprintf
** File description:
** libC
*/
#include "../include/lem_in.h"

int my_sprintf(char *str, const char *format, ...)
{
    va_list args;
    int len = 0;
    char buffer[1024] = {0};

    va_start(args, format);
    len = format_string(buffer, format, args);
    va_end(args);

    if (len >= 1024) {
        return (-1);
    }

    string_copy(str, buffer);
    return (len);
}

int format_string(char *buffer, const char *format, va_list args)
{
    int i, j;
    char temp[1024] = {0};
    for (i = 0, j = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c': temp[j] = (char) va_arg(args, int), j++; break;
                case 'd': j += int_to_string(temp + j, va_arg(args, int));
                break;
                case 's': j += string_copy(temp + j, va_arg(args, char *));
                break;
                default:
                    write(2, "Error with undefined flag.\n", 27);
                    break;
            }
        } else
            temp[j] = format[i], j++;
    }
    string_copy(buffer, temp);
    return (j);
}

int int_to_string(char *str, int num)
{
    int i, len = 0, neg = 0;

    if (num < 0) {
        neg = 1;
        num = -num;
    } do {
        str[len] = num % 10 + '0';
        len++, num /= 10;
    } while (num > 0);
    if (neg) {
        str[len] = '-', len++;
    }
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1], str[len - i - 1] = temp;
    }
    return (len);
}

int string_copy(char *dest, const char *src)
{
    int i, len = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        len++;
    }

    return (len);
}
