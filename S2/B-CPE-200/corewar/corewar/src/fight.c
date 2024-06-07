/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** fight
*/

#include "corewar.h"

void finishhim(vm *machine, int *dying)
{
    for (champ *tmp = machine->all; tmp; tmp = tmp->next) {
        if (tmp->live != 1) {
            tmp->live = *dying;
            (*dying)--;
        } else
            tmp->live = 0;
    }
}

void whowin(vm *machine)
{
    champ *victory = NULL;
    int classement = 0;
    for (champ *tmp = machine->all; tmp; tmp = tmp->next) {
        if (tmp->live < classement) {
            classement = tmp->live;
            victory = tmp;
        }
    }
    my_putstr("The player ");
    my_put_nbr(victory->id);
    my_putchar('(');
    my_putstr(victory->name);
    my_putstr(")WIN!\n");
}

int conditionend(vm *machine)
{
    int check = 0;
    for (champ *tmp = machine->all; tmp; tmp = tmp->next) {
        if (tmp->live != 0 || tmp->live != 1)
            check++;
    }
    if (check == machine->nbrchamp)
        return 0;
    return 1;
}

void csfight(vm **machine)
{
    for (champ *tmp = (*machine)->all; tmp; tmp = tmp->next) {
        if (tmp->live >= 0)
            actionforallpc(&tmp, machine);
    }
}

void fightmain(vm *machine)
{
    int nbrofcycle = 0, endofturn = CYCLE_TO_DIE, dying = -1;
    while (1) {
        //printf("CYCLE : %i\n", nbrofcycle);
        if (machine->dump != 0 && machine->dump == nbrofcycle) {
            machine->dump = 0;
            showarena(machine->arena, machine->all);
        }
        csfight(&machine);
        nbrofcycle++;
        if (nbrofcycle >= endofturn) {
            finishhim(machine, &dying);
            nbrofcycle = 0;
        }
        if (machine->counterlive >= NBR_LIVE) {
            endofturn -= CYCLE_DELTA;
            machine->counterlive = 0;
        }
    }
    whowin(machine);
}
