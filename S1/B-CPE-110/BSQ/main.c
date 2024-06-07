/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** main
*/

#include "my.h"

int main (int ar, char **av)
{
    if (ar == 2)
        return bsq(av[1]);
    if (ar == 3)
        return generate(av);
    return 84;
}
