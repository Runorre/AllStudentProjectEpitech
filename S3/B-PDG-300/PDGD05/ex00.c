/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** ex00
*/

#include "string.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void string_init(string_t *this, const char *s)
{
    this->str = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(this->str, s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
}

void string_destroy(string_t *this)
{
    if (this) {
        free(this->str);
    }
}
