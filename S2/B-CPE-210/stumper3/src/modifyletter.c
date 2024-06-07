/*
** EPITECH PROJECT, 2023
** Cesar
** File description:
** modify a letter
*/

#include "my.h"

void modify_min_letter(int key, char *buffer, int i)
{
    int tmp_int = 0;
    char tmp_char = buffer[i];
    while (tmp_int != key) {
        if (key < 0) {
            tmp_char--;
            tmp_int--;
        } else {
            tmp_char++;
            tmp_int++;
        }
        if (tmp_char < 'a')
            tmp_char = 'z';
        if (tmp_char > 'z')
            tmp_char = 'a';
    }
    buffer[i] = tmp_char;
}

void modify_maj_letter(int key, char *buffer, int i)
{
    int tmp_int = 0;
    char tmp_char = buffer[i];
    while (tmp_int != key) {
        if (key < 0) {
            tmp_char--;
            tmp_int--;
        } else {
            tmp_char++;
            tmp_int++;
        }
        if (tmp_char < 'A')
            tmp_char = 'Z';
        if (tmp_char > 'Z')
            tmp_char = 'A';
    }
    buffer[i] = tmp_char;
}
