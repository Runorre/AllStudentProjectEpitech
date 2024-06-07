/*
** EPITECH PROJECT, 2023
** Blank
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **ar)
{
    vm *opt = init(ac, ar);
    opt->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i != MEM_SIZE; i++)
        opt->arena[i] = 0;
    if (opt == NULL || opt->nbrchamp == 1)
        return 84;
    addprograminarena(opt, &opt->arena);
    fightmain(opt);
    free(opt->arena);
    return 0;
}
