/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*TODO*/
int f_aff(pc **p, vm **machine, arg_t *argu, short int function)
{
    my_putchar((*p)->reg[argu->ar - 1]);
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    return 0;
}
