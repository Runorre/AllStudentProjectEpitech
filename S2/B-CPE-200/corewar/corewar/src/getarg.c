/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** checkarg
*/

#include "corewar.h"

arg_t *addargument(arg_t *current, int type, int argument)
{
    arg_t *new = malloc(sizeof(arg_t));
    new->type = type;
    new->ar = argument;
    new->next = current;
    return new;
}

arg_t *case_reg(int *tmppc, arg_t *a, vm *machine)
{
    (*tmppc)++;
    short int indice = machine->arena[(*tmppc)];
    return addargument(a, T_REG, indice);
}

arg_t *case_dir(int *tmppc, arg_t *a, vm *machine)
{
    (*tmppc)++;
    int indice = 0;
    for (int i = 24; i >= 0; i -= 8) {
        indice = (machine->arena[(*tmppc)] << i);
        (*tmppc)++;
    }
    return addargument(a, T_DIR, indice);
}

arg_t *case_ind(int *tmppc, arg_t *a, vm *machine, int pc)
{
    (*tmppc)++;
    short int indice3 = 0;
    for (int i = 8; i >= 0; i -= 8) {
        indice3 = (machine->arena[(*tmppc)] << i);
        (*tmppc)++;
    }
    return addargument(a, T_IND, indice3);
}

int checkarg(char argument, int (*tmppc)[2], arg_t *a, vm *machine)
{
    switch (argument & 0b11000000) {
        case M_REG:
            a = case_reg(&(*tmppc)[0], a, machine);
            break;
        case M_DIR:
            a = case_dir(&(*tmppc)[0], a, machine);
            break;
        case M_IND:
            a = case_ind(&(*tmppc)[0], a, machine, (*tmppc)[1]);
            break;
        default:
            return 1;
        }
    return 0;
}
