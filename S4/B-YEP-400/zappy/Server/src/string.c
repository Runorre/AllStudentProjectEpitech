/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** string
*/

#include "../include/server.h"

void string_init(string_t *str)
{
    str->data = calloc(1024, sizeof(char));
    str->len = 0;
    str->cap = 1024;
}

void string_append(string_t *str, const char *append)
{
    size_t append_len = strlen(append);

    while ((str->len + append_len + 1) > str->cap) {
        str->cap *= 2;
        str->data = realloc(str->data, str->cap);
    }
    strcpy(str->data + str->len, append);
    str->len += append_len;
}

void string_free(string_t *str)
{
    free(str->data);
    str->len = 0;
    str->cap = 0;
}
