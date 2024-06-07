/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** createarena
*/

#include "corewar.h"

int checkcaract(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

void oneprog(char **arena, int whereinmemory, champ **prg)
{
    int header = 0, tmp = whereinmemory, i = 0;
    (*prg)->start = whereinmemory; (*prg)->allpc->pc = whereinmemory;
    char *str = malloc(sizeof(char) * 1);
    (*prg)->name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    while (fread(str, 1, 1, (*prg)->fd) != 0) {
        if (header <= PROG_NAME_LENGTH && checkcaract(str[0])) {
            (*prg)->name[i] = str[0]; i++;
        } if (header <= (PROG_NAME_LENGTH + COMMENT_LENGTH + 15))
            header++;
        else {
            (*arena)[tmp] = str[0];
            tmp++;
        }
    }
    (*prg)->end = tmp;
    free(str);
}

int addprograminarena(vm *opt, char **arena)
{
    int move = MEM_SIZE / opt->nbrchamp;
    int whereinmemory = 0;
    for (champ *tmp = opt->all; tmp; tmp = tmp->next) {
        oneprog(arena, whereinmemory, &tmp);
        whereinmemory += move;
    }
    return 0;
}
