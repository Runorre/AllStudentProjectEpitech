/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex01
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

void assign_s(string_t *this, const string_t *str)
{

    if (this && str) {
        free(this->str);
        this->str = calloc(strlen(str->str) + 1, sizeof(char));
        this->str = strcpy(this->str, str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (this) {
        free(this->str);
        this->str = calloc(strlen(s) + 1, sizeof(char));
        this->str = strcpy(this->str, s);
    }
}
