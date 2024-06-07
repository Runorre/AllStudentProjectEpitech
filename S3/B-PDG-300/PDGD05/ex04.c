/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex04
*/

#include "string.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void clear(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = calloc(1, sizeof(char));
    strcpy(this->str, "");
}
