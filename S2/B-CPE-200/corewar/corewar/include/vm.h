/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** vm
*/

#ifndef VM_H_
    #define VM_H_
    #include "corewar.h"
    typedef struct virtualmachine{
        int dump;
        int n;
        int next_a;
        int (*pgr[16])(pc **p, struct virtualmachine **machine, arg_t *arg,
        short int func);
        int nbrchamp;
        int counterlive;
        char *arena;
        int tmp_live;
        champ *all;
    }vm;
#endif /* !VM_H_ */
