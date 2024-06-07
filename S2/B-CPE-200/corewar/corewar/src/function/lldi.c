/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

int getarg_i(pc **p, arg_t *argu, vm **machine)
{
    int final = 0;
    if (argu->type == T_REG)
        final += (*p)->reg[argu->ar - 1];
    if (argu->type == T_IND) {
        int go = (*p)->pc + argu->ar;
        int tmp = 0;
        for (int i = 24; i >= 0; i -= 8) {
            tmp = ((*machine)->arena[go] << i);
            go++;
        }
        final += tmp;
    }
    if (argu->type == T_DIR)
        final += argu->ar;
    return final;
}

int getarg_ni(pc **p, int where, vm **machine)
{
    int final = 0;
    int go = (*p)->pc + where;
    int tmp = 0;
    for (int i = 24; i >= 0; i -= 8) {
        tmp = ((*machine)->arena[go] << i);
        go++;
    }
    final += tmp;
    return final;
}

/*like ldi but no IDX_MOD*/
int f_lldi(pc **p, vm **machine, arg_t *argu, short int function)
{
    int s = getarg_i(p, argu, machine);
    arg_t *hello = argu->next;
    s += getarg_i(p, hello, machine);
    hello = argu->next;
    (*p)->reg[hello->ar - 1] = getarg_ni(p, s, machine);
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    (*p)->carry = 1;
    return 1;
}
