/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** flags2
*/

#include "my.h"

int all_flag(char **argv, int x)
{
    if (flag_g(argv) == 84) {
        return (84);
    } else if (flag_s(argv, x) == 84) {
        return (84);
    }
    if (flag_w(argv, x) == 84) {
        return (84);
    }
    return (0);
}

int number_flag(char **argv)
{
    int x = 0;
    int g = 0, s = 0, w = 0;
    while (argv[x] != NULL) {
        if (strncmp(argv[x], "-g", 2) == 0) {
            g++;
        }
        if (strncmp(argv[x], "-s", 2) == 0) {
            s++;
        }
        if (strncmp(argv[x], "-w", 2) == 0) {
            w++;
        }
        x++;
    }
    if (g > 1 || s > 1 || w > 1) {
        return (84);
    }
    return (0);
}

int correct_string(char **argv)
{
    int x = 0;
    while (argv[x] != NULL) {
        if ((argv[x][0] == '-') && (argv[x][1] != 'g' &&
           argv[x][1] != 's' && argv[x][1] != 'w')) {
            return (84);
        }
        x++;
    }
    return (0);
}

int result(char **argv, int x)
{
    if (number_flag(argv) != 84 &&
        correct_string(argv) != 84) {
        if (all_flag(argv, x) == 84) {
            return (84);
        }
    } else {
        return (84);
    }
    return (0);
}

