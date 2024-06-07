/*
** EPITECH PROJECT, 2023
** Cesar
** File description:
** all file fonct
*/

#include "my.h"

void file_line_cesar(int key, char *buffer, int cryptfd)
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

void file_cesar(int key, FILE *fd, int cryptfd)
{
    size_t len = 0;
    char *buffer = NULL;
    while (getline(&buffer, &len, fd) != -1) {
        file_line_cesar(key, buffer, cryptfd);
    }
    free(buffer);
}
