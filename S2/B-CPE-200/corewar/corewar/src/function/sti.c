/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*sti*/
int f_sti(pc **p, vm **machine, arg_t *argu, short int function)
{
    int stock = (*p)->reg[argu->ar - 1];
    arg_t *hello = argu->next;
    int where = hello->ar + hello->next->ar;
    int tmppc = ((*p)->pc + where % IDX_MOD);
    for (int i = 24; i >= 0; i -= 8) {
        (*machine)->arena[tmppc] = (stock >> i) & 0xFF;
        tmppc++;
    }
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    (*p)->carry = 1;
    return 0;
}
