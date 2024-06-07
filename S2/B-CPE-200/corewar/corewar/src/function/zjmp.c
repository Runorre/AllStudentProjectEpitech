/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*jump into memory*/
int f_xjmp(pc **p, vm **machine, arg_t *argu, short int function)
{
    int indice = 0, tmppc = (*p)->pc;
    for (int i = 24; i >= 0; i -= 8) {
        indice = ((*machine)->arena[tmppc] << i);
        tmppc++;
    }
    if ((*p)->carry == 1)
        (*p)->pc += indice % IDX_MOD;
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    return 0;
}
