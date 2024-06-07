/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** live
*/

#include "corewar.h"

/*live*/
int f_live(pc **p, vm **machine, arg_t *argu, short int function)
{
    printf("LIVE\n");
    (*machine)->tmp_live = 1;
    (*p)->wait = op_tab[function - 1].nbr_cycles;
    return 0;
}
