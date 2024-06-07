/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** char
*/

#include "../include/server.h"

int count_char(const char *str, char ch)
{
    int count = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int last_char(const char *str, char ch)
{
    int count = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count = i;
        }
    }
    return count;
}

char *my_strcut(const char *str, int pos)
{
    char *new_str = malloc(sizeof(char) * (pos + 1));
    int i = 0;

    for (i = 0; i != pos; i++) {
        new_str[i] = str[i];
    }
    new_str[i] = '\0';
    return new_str;
}
