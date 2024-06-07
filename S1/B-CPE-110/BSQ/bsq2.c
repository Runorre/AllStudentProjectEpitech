/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** bsq2
*/

#include "my.h"

int bsq2(char **av)
{
    if (findbigsquare(av) == 1) {
        return 84;
    }
    return 0;
}
