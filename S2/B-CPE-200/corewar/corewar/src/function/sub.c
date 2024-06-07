/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*sub arg 1 and arg 2 into arg 3 (reg)*/
int f_sub(pc **p, vm **machine, arg_t *argu, short int function)
{
    int final = (*p)->reg[argu->ar - 1];
    arg_t *hello = argu->next;
    final -= (*p)->reg[hello->ar - 1];
    hello = hello->next;
    (*p)->reg[hello->ar - 1] = final;
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    (*p)->carry = 1;
    return 1;
}
