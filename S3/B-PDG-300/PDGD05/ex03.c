/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex03
*/

#include "string.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char at(const string_t *this, size_t pos)
{
    for (size_t i = 0; this->str[i] != '\0'; i++) {
        if (i == pos) {
            return this->str[i];
        }
    }
    return -1;
}
