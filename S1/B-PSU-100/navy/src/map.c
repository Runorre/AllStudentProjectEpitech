/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy
** File description:
** map
*/

#include "my.h"

int alpha_int(char *c)
{
    int nbr = c[0];
    if (65 <= nbr && nbr <= 90)
        return (nbr - 64);
    if (97 <= nbr && nbr <= 122)
        return (nbr - 96);
    return (0);
}

void save_joueur_map(map_s *map, char *line)
{
    char **tbl = my_str_to_word_array(line);
    char pion = tbl[0][0];
    int get = my_getnbr(tbl[1]) - 1, alp = alpha_int(tbl[1]) - 1;
    for (int i = 0; i < my_getnbr(tbl[0]); i++) {
        if (alpha_int(tbl[1]) == alpha_int(tbl[2]))
            map->joueur_map[(i + get)][alp] = pion;
        if (my_getnbr(tbl[1]) == my_getnbr(tbl[2]))
            map->joueur_map[get][(i + alp)] = pion;
    }
}

int read_map(map_s *map, char *av)
{
    FILE *stream = fopen(av, "r");
    int counter = 0;
    if (!(stream))
        return 84;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stream) != -1) {
        if (verif_line(line, ('2' + counter)) != 0 || counter > 3)
            return (84);
        save_joueur_map(map, line);
        counter++;
    }
    free(line);
    fclose(stream);
    if (counter != 3)
        return 84;
    return (0);
}

map_s *ini_map(map_s *map)
{
    map = malloc(sizeof(map_s));
    int i = 0;
    if (map == NULL)
        return (NULL);
    map->lose = 0;
    map->joueur_map = malloc(sizeof(char *) * 8);
    map->enemy_map = malloc(sizeof(char *) * 8);
    while (i <= 7) {
        map->joueur_map[i] = malloc(sizeof(char) * 9);
        map->enemy_map[i] = malloc(sizeof(char) * 9);
        for (int e = 0; e != 8; e++) {
            map->joueur_map[i][e] = '.';
            map->enemy_map[i][e] = '.';
        }
        i++;
    }
    return (map);
}

void print_map(map_s *map)
{
    my_putstr("my positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i <= 7; i++) {
        my_printf("%i|%c", i + 1, map->joueur_map[i][0]);
        for (int n = 1; n <= 7; n++) {
            my_printf(" %c", map->joueur_map[i][n]);
        }
        my_putstr("\n");
    }
    my_putstr("\nenemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i <= 7; i++) {
        my_printf("%i|%c", i + 1, map->enemy_map[i][0]);
        for (int n = 1; n <= 7; n++) {
            my_printf(" %c", map->enemy_map[i][n]);
        }
        my_putstr("\n");
    }
}
