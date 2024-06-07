/*
** EPITECH PROJECT, 2023
** src/find_character
** File description:
** libC
*/
#include "../include/lem_in.h"

int find_character(char *text, char char_to_find)
{
    while (*text) {
        if (*text == char_to_find) {
            return 1;
        }
        text++;
    }
    return 0;
}
