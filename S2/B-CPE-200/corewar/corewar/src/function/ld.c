/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** ld
*/

#include "corewar.h"

/*ld stock argu 1 to argu 2*/
int f_ld(pc **p, vm **machine, arg_t *argu, short int function)
{
    int stocking = 0;
    if (argu->type == T_REG)
        stocking = (*p)->reg[argu->ar - 1];
    if (argu->type == T_IND) {
        stocking = argu->ar;
        int go = (*p)->pc + stocking % IDX_MOD;
        int tmp = 0;
        for (int i = 24; i >= 0; i -= 8) {
            tmp = ((*machine)->arena[go] << i);
            go++;
        }
        stocking = tmp;
    }
    if (argu->type == T_DIR)
        stocking = argu->ar;
    arg_t *hello = argu->next;
    (*p)->reg[hello->ar - 1] = stocking;
    (*p)->wait = op_tab[function - 1].nbr_cycles; (*p)->carry = 1;
    return 1;
}
