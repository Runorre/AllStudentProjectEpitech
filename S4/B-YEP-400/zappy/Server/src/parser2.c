/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** parser2
*/

#include "../include/server.h"

void error_handeling_parse(const char *arg)
{
    if ((strcmp(arg, "-f") != 0) && (strcmp(arg, "-p") != 0)
        && (strcmp(arg, "-x") != 0) && (strcmp(arg, "-y") != 0)
        && (strcmp(arg, "-c") != 0)) {
        exit(84);
    }
}
