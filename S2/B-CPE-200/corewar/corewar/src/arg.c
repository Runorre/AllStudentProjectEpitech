/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** arg
*/

#include "corewar.h"

int getarg_n(pc **p, int where, vm **machine)
{
    int final = 0;
    int go = (*p)->pc + where % IDX_MOD;
    int tmp = 0;
    for (int i = 24; i >= 0; i -= 8) {
        tmp = ((*machine)->arena[go] << i);
        go++;
    }
    final += tmp;
    return final;
}

int getarg(pc **p, arg_t *argu, vm **machine)
{
    int final = 0;
    if (argu->type == T_REG)
        final += (*p)->reg[argu->ar - 1];
    if (argu->type == T_IND) {
        int go = (*p)->pc + argu->ar % IDX_MOD;
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

void putlive(champ *p)
{
    my_putstr("The player ");
    my_put_nbr(p->id);
    my_putchar('(');
    my_putstr(p->name);
    my_putstr(")is alive.\n");
}

int actionpgrm(pc **p, vm **machine)
{
    short int funct = (*machine)->arena[(*p)->pc];
    if (funct == 1 || funct == 9 || funct == 12 || funct == 15) {
        (*machine)->pgr[funct - 1](p, machine, NULL, funct); (*p)->pc += 5;
        return 0;
    }int tmppc[] = {(*p)->pc + 1, (*p)->pc}, wrong = 0, e = 0;
    char argument = (*machine)->arena[tmppc[0]]; arg_t *a = NULL;
    while (!wrong && e != 4) {
        wrong = checkarg(argument, &tmppc, a, (*machine));
        argument <<= 2; e++;
    } int check = 0;
    for (arg_t *tmp = a; tmp; tmp = tmp->next) {
        if (tmp->type & op_tab[funct - 1].type[check] == 0) {
            (*p)->carry = 0; return 0;
        } check++;
    }
    if ((check + 1) != op_tab[funct - 1].nbr_args) {
        (*p)->carry = 0; return 0;
    } (*machine)->pgr[funct - 1](p, machine, a, funct);
    if (funct != 9)
        (*p)->pc = tmppc[0] + 1;
}

void actionforallpc(champ **p, vm **machine)
{
    int ltmp = 0;
    for (pc *tmp = (*p)->allpc; tmp; tmp = tmp->next) {
        if (tmp->wait == 0) {
            actionpgrm(&tmp, machine);
            ltmp = (*machine)->tmp_live;
        } else
            tmp->wait--;
        if (tmp->pc >= (*p)->end)
            tmp->pc = (*p)->start;
    }
    if (ltmp) {
        (*p)->live = 1;
        putlive((*p));
        (*machine)->counterlive++;
    }
    (*machine)->tmp_live = 0;
}
