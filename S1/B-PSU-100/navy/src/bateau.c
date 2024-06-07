/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy
** File description:
** bateau
*/

#include "my.h"

int *get_request_p(void)
{
    char *line = NULL;
    size_t len = 0;
    my_putstr("attack: ");
    getline(&line, &len, stdin);
    if (my_strlen(line) != 3 || !(line[0] >= 'A' && line[0] <= 'H')
        || !(line[1] >= '1' && line[1] <= '8')) {
            my_putstr("wrong position\n");
            return get_request_p();
    }
    int *result = malloc(sizeof(int) * 2);
    result[0] = alpha_int(line) - 1;
    result[1] = my_getnbr(line) - 1;
    return result;
}

int verif_pos_ship(char **map, int *pos)
{
    if (map[pos[1]][pos[0]] == '.' ||
        map[pos[1]][pos[0]] == 'o' ||
        map[pos[1]][pos[0]] == 'x')
        return (0);
    else {
        map[pos[1]][pos[0]] = 'x';
        return (1);
    }
    convertcood(pos);
}

void verif_lose(map_s *map)
{
    int y = 0, x = 0, lose = 1;
    while (y != 8) {
        if (x >= 8) {
            x = 0;
            y++;
        }
        if (x < 8 && y < 8 &&
            map->joueur_map[y][x] >= '0' &&
            map->joueur_map[y][x] <= '9')
            lose = 0;
        x++;
    }
    if (lose == 1)
        map->lose = 1;
}

int *convertcood(int *pos)
{
    char c1 = pos[0] + 'A';
    my_putchar(c1);
    my_put_nbr(pos[1] + 1);
    my_putstr(": ");
    return pos;
}
