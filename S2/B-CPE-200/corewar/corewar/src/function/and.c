/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*put in argu 3 = argu 1 & argu 2*/
int f_and(pc **p, vm **machine, arg_t *argu, short int function)
{
    int final = getarg(p, argu, machine);
    arg_t *hello = argu->next;
    final &= getarg(p, hello, machine);
    hello = hello->next;
    (*p)->reg[hello->ar - 1] = final;
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    (*p)->carry = 1;
    return 1;
}
