/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex02
*/

#include "string.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void append_s(string_t *this, const string_t *ap)
{
    this->str = realloc(this->str, (strlen(this->str) + strlen(ap->str) + 1));
    if (this)
        this->str = strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    this->str = realloc(this->str, (strlen(this->str) + strlen(ap) + 1));
    if (this)
        this->str = strcat(this->str, ap);
}
