/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** error_tmp
*/

#include "lem_in.h"

void free_forgor(char* str, char* buf, char** lines, pars_t* parse)
{
    if (parse) free(parse);
    if (str) free(str);
    if (buf) free(buf);
    if (lines) free_2d_array(lines);
}

int bad_file(pars_t* parse)
{
    if (parse->nb_ants <= 0)
        return 1;
    if (parse->beginning == 0 || parse->end == 0)
        return 1;
    if (parse->e != 1 || parse->s != 1) return 1;
    return 0;
}
