/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*fork*/
int f_fork(pc **p, vm **machine, arg_t *argu, short int function)
{
    int indice = 0, tmppc = (*p)->pc;
    for (int i = 24; i >= 0; i -= 8) {
        indice = ((*machine)->arena[tmppc] << i);
        tmppc++;
    }
    int newpc = (*p)->pc + indice % IDX_MOD;
    pc *tmp = *p;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(pc));
    tmp->next->pc = newpc;
    tmp->next->wait = op_tab[function - 1].nbr_cycles;
    for (int i = 0; i != 16; i++)
        tmp->next->reg[i] = (*p)->reg[i];
    tmp->carry = (*p)->carry;
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    return 0;
}
