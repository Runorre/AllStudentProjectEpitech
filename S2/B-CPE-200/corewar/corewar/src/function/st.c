/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*Store the first in second argu (modify memory) */
int f_st(pc **p, vm **machine, arg_t *argu, short int function)
{
    int socking = (*p)->reg[argu->ar - 1];
    arg_t *hello = argu->next;
    if (hello->type == T_REG) {
        (*p)->reg[hello->ar - 1] = socking;
    } else {
        int tmppc = ((*p)->pc + hello->ar % IDX_MOD);
        for (int i = 24; i >= 0; i -= 8) {
            (*machine)->arena[tmppc] = (socking >> i) & 0xFF;
            tmppc++;
        }
    }
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    return 0;
}
