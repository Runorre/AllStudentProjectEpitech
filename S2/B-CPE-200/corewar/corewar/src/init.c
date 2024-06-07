/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** init
*/

#include "corewar.h"

pc *addpc(pc *list, int idchamp, int start)
{
    pc *new = malloc(sizeof(pc));
    new->pc = start;
    new->next = list;
    new->wait = 0;
    new->carry = 0;
    new->reg[0] = idchamp;
    for (int i = 1; i != 16; i++) {
        new->reg[i] = 0;
    }
    return new;
}

vm *checktirer(vm *opt, char **ar, int where)
{
    if (ar[where + 1] == NULL)
        return NULL;
    if (my_strcmp("-a", ar[where])) {
        opt->next_a = my_getnbr(ar[where + 1]);
        return opt;
    }
    if (my_strcmp("-dump", ar[where])) {
        if (opt->dump == -1)
            return NULL;
        else {
            opt->dump = my_getnbr(ar[where + 1]);
            return opt;
        }
    }
    return NULL;
}

vm *addchamp(char **ar, int where, vm *opt)
{
    FILE *fd = fopen(ar[where], "r");
    if (fd == NULL)
        return NULL;
    champ *tmp = opt->all;
    while (tmp && tmp->next)
        tmp = tmp->next;
    if (tmp) {
        tmp->next = malloc(sizeof(champ)); tmp->next->fd = fd;
        tmp->next->allpc = addpc(NULL, opt->nbrchamp, 0);
        tmp->next->next = NULL;
        tmp->next->wait = 0; tmp->next->id = opt->nbrchamp;
    } else {
        opt->all = malloc(sizeof(champ));
        opt->all->allpc = addpc(NULL, opt->nbrchamp, 0);
        opt->all->id = opt->nbrchamp; opt->all->fd = fd; opt->all->wait = 0;
        opt->all->next = NULL;
    }
    return opt;
}

vm *initfunction(vm *opt)
{
    opt->counterlive = 0;
    opt->pgr[0] = f_live;
    opt->pgr[1] = f_ld;
    opt->pgr[2] = f_st;
    opt->pgr[3] = f_add;
    opt->pgr[4] = f_sub;
    opt->pgr[5] = f_and;
    opt->pgr[6] = f_or;
    opt->pgr[7] = f_xor;
    opt->pgr[8] = f_xjmp;
    opt->pgr[9] = f_ldi;
    opt->pgr[10] = f_sti;
    opt->pgr[11] = f_fork;
    opt->pgr[12] = f_lld;
    opt->pgr[13] = f_lldi;
    opt->pgr[14] = f_lfork;
    opt->pgr[15] = f_aff;
    return opt;
}

vm *init(int ac, char **ar)
{
    if (ac == 1)
        return NULL;
    vm *opt = malloc(sizeof(vm));
    opt->dump = -1; opt->n = -1; opt->next_a = -1;
    opt->nbrchamp = 1; opt->all = NULL; opt->tmp_live = 0;
    for (int i = 1; ar[i]; i++) {
        if (ar[i][0] == '-') {
            opt = checktirer(opt, ar, i);
            i++;
        } else {
            opt = addchamp(ar, i, opt);
            opt->nbrchamp++;
        }
        if (opt == NULL)
            return NULL;
    }
    opt->nbrchamp--;
    return initfunction(opt);
}
