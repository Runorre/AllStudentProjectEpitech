/*
** EPITECH PROJECT, 2023
** src/my_calloc
** File description:
** libC
*/
#include "../include/lem_in.h"

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    unsigned char uc = c;
    while (n-- > 0) {
        *p++ = uc;
    }
    return s;
}

void *my_calloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);
    if (ptr != NULL) {
        my_memset(ptr, 0, count * size);
    }
    return ptr;
}
