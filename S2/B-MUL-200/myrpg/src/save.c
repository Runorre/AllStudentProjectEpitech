/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** save
*/

#include "rpg.h"

void write_stat(stats_s* stats, FILE *save)
{
    char **struct_stats = malloc(sizeof(char *) * (8));
    int i = 0;
    struct_stats[0] = my_int_to_char(stats->attack);
    struct_stats[1] = my_int_to_char(stats->defense);
    struct_stats[2] = my_int_to_char(stats->magie);
    struct_stats[3] = my_int_to_char(stats->hp);
    struct_stats[4] = my_int_to_char(stats->max_hp);
    struct_stats[5] = my_int_to_char(stats->mp);
    struct_stats[6] = my_int_to_char(stats->max_mp);
    struct_stats[7] = NULL;
    while (struct_stats[i]) {
        fwrite(struct_stats[i], my_strlen(struct_stats[i]), 1, save);
        fwrite("|", 1, 1, save);
        i++;
    }
    for (i = 0; struct_stats[i]; i++)
        free(struct_stats[i]);
    free(struct_stats);
}

void write_spells(sfBool b, FILE *save)
{
    if (b == true) {
        fwrite("1", 1, 1, save);
        fwrite("|", 1, 1, save);
    } else {
        fwrite("0", 1, 1, save);
        fwrite("|", 1, 1, save);
    }
}

void write_lvl(level_s* level, FILE* save)
{
    char* lvl = my_int_to_char(level->lvl);
    char* xp = my_int_to_char(level->exp);
    fwrite(lvl, my_strlen(lvl), 1, save);
    fwrite("\n", 1, 1, save);
    fwrite(xp, my_strlen(xp), 1, save);
}

void write_map(champ_s* champion, FILE* save)
{
    char* map_id = my_int_to_char(champion->map);
    fwrite(map_id, my_strlen(map_id), 1, save);
    fwrite("\n", 1, 1, save);
    sfVector2f pos = sfSprite_getPosition(champion->sprite);
    char* x = my_int_to_char(pos.x);
    char* y = my_int_to_char(pos.y);
    fwrite(x, my_strlen(x), 1, save);
    fwrite("\n", 1, 1, save);
    fwrite(y, my_strlen(y), 1, save);
    fwrite("\n", 1, 1, save);
}

void save(champ_s *champion)
{
    FILE *save = fopen("save", "w+");
    fwrite(champion->name, my_strlen(champion->name), 1, save);
    fwrite("\n", 1, 1, save);
    write_stat(champion->stats, save);
    fwrite("\n", 1, 1, save);
    write_lvl(champion->level, save);
    fwrite("\n", 1, 1, save);
    write_spells(champion->q1, save);
    write_spells(champion->q2, save);
    write_spells(champion->q3, save);
    fwrite("\n", 1, 1, save);
    write_map(champion, save);
    fclose(save);
}
