/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** append
*/

#include "../include/server.h"

void appendtofile(const char *filename, const char *line)
{
    FILE *file = fopen(filename, "a");

    if (file == NULL)
        return;
    fprintf(file, "%s\n", line);
    fclose(file);
}
