/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex05
*/

#include "string.h"
#include <stddef.h>

int length(const string_t *this)
{
    int i = 0;

    if (!this && !this->str)
        return -1;
    while(this->str[i] != '\0')
        i++;
    return i;
}