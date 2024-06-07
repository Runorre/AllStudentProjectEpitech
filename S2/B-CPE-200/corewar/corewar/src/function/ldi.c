/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*ldi*/
int f_ldi(pc **p, vm **machine, arg_t *argu, short int function)
{
    int s = getarg(p, argu, machine);
    arg_t *hello = argu->next;
    s += getarg(p, hello, machine);
    hello = argu->next;
    (*p)->reg[hello->ar - 1] = getarg_n(p, s, machine);
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    (*p)->carry = 1;
    return 1;
}
