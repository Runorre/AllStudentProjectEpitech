/*
** EPITECH PROJECT, 2023
** lib/my/my_strspn
** File description:
** libC
*/
#include "my.h"

int char_in_charset(char c, const char *charset)
{
    for (size_t i = 0; charset[i] != '\0'; i++) {
        if (c == charset[i]) {
            return 1;
        }
    }
    return 0;
}

size_t my_strspn(const char *str, const char *charset)
{
    size_t i;

    for (i = 0; str[i] != '\0' && char_in_charset(str[i], charset); i++);

    return i;
}
