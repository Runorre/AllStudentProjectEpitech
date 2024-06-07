/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** get_save
*/

#include "rpg.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

int malloc_size_buffer(int fd, int *taille)
{
    struct stat fichier;
    fstat(fd, &fichier);
    *taille = fichier.st_size;
    return (fichier.st_size);
}

char *recup_fichier(int fd)
{
    int taille = 0;
    char *buffer = malloc(sizeof(char) * malloc_size_buffer(fd, &taille) + 1);
    read(fd, buffer, taille);
    close(fd);
    buffer[taille] = 0;
    return (buffer);
}

champ_s *recup_sauvegarde(map_s **map)
{
    int fd = open("save", O_RDONLY);
    if (fd < 0)
        return (NULL);
    char *buffer = recup_fichier(fd);
    char **fichier = char_en_char_double(buffer);
    champ_s *champion = init_mc((sfVector2f){0, 0});
    champion->name = my_strdup(fichier[0]);
    champion->stats = recup_stats(fichier[1]);
    champion->level->lvl = str_to_int(fichier[2]);
    champion->level->exp = str_to_int(fichier[3]);
    champion = get_inv(champion, fichier[4]);
    (*map) = recup_map(fichier[5], fichier[6], fichier[7], &champion);
    return (champion);
}
