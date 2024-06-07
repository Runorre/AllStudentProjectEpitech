/*
** EPITECH PROJECT, 2023
** Cesar
** File description:
** string arg
*/

#include "my.h"

void str_line_cesar(int key, char *buffer, int cryptfd)
{
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            modify_maj_letter(key, buffer, i);
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
            modify_min_letter(key, buffer, i);
        i++;
    }
    write(cryptfd, buffer, my_strlen(buffer));
}
