/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** map
*/

#include "my.h"

char **getmap(char const *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(84);
    struct stat s;
    stat(path, &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size] = '\0';
    if (buffer[0] != '\0') {
        char **square = my_str_to_word_array(buffer);
        free(buffer);
        return square;
    } else {
        char **square = malloc(sizeof(char *) * 1);
        free(buffer);
        return square;
    }
}

void find_p(struct data *d)
{
    int p = 0, i = 0, j = 0;
    d->nbr_o = 0, d->nbr_x = 0;
    while (d->map[i] != NULL) {
        if (d->map[i][j] == 'P') {
            d->p_x = j;
            d->p_y = i;
            p++;
        }
        if (d->map[i][j] == 'O')
            d->nbr_o++;
        if (d->map[i][j] == 'X')
            d->nbr_x++;
        if (d->map[i][j] == '\0') {
            i++;
            j = 0;
        } else
            j++;
    }
    if (p == 0 || p > 1 || (d->nbr_o != d->nbr_x || d->nbr_o == 0))
        exit(84);
}

void memory(struct data *d)
{
    d->co_o = malloc(sizeof(int *) * d->nbr_o);
    for (int i = 0; i != d->nbr_o; i++) {
        d->co_o[i] = malloc(sizeof(int) * 2);
    }
}

void find_ox(struct data *d)
{
    int i = 0, j = 0, z = 0;
    memory(&(*d));
    while (d->map[i] != NULL) {
        if (d->map[i][j] == 'O') {
            d->co_o[z][0] = i;
            d->co_o[z][1] = j;
            z++;
        }
        if (d->map[i][j] == '\0') {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
}

struct data create_data(char *path)
{
    struct data d;
    d.path = path;
    d.map = create_map_em(path);
    find_p(&d);
    find_ox(&d);
    return d;
}
