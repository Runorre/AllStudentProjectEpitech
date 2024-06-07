/*
** EPITECH PROJECT, 2022
** my_realloc
** File description:
** lem_in
*/
#include "../include/lem_in.h"

void *my_realloc(void *ptr, size_t size)
{
    size_t old_size, copy_size;
    void *new_ptr;
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        old_size = my_strlen(ptr) + 1;
        copy_size = old_size < size ? old_size : size;
        my_memcpy(new_ptr, ptr, copy_size);
        free(ptr);
    }

    return new_ptr;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    if (n == 0) {
        return dest;
    }

    while (n-- > 0) {
        *d++ = *s++;
    }

    return dest;
}
