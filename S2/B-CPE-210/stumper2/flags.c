/*
** EPITECH PROJECT, 2023
** flags.c
** File description:
** Management of flags
*/

#include "my.h"

int alpha(char **argv, int u)
{
    int y = 0;
    while (argv[u][y] != '\0') {
        if (argv[u][y] < 97 || argv[u][y] > 122) {
            return (1);
        }
        y++;
    }
    return (0);
}

int number(char **argv, int u)
{
    int y = 0;
    while (argv[u][y] != '\0') {
        if (argv[u][y] < 48 || argv[u][y] > 57) {
            return (1);
        }
        y++;
    }
    return (0);
}

int flag_g(char **argv)
{
    if (strncmp(argv[1], "-g", 2) == 0) {
        if (alpha(argv, 2) == 0) {
            return (0);
        }
    }
    return (84);
}

int flag_s(char **argv, int x)
{
    int y = 0;
    if (strncmp(argv[x], "-s", 2) == 0) {
        y = x + 1;
        if (number(argv, y) != 0) {
            return (84);
        }
    }
    return (0);
}

int flag_w(char **argv, int x)
{
    int y = 0;
    if (strncmp(argv[x], "-w", 2) == 0 && x > 1) {
        y = x + 1;
        if (alpha(argv, y) == 1) {
            return (84);
        }
    }
    return (0);
}

