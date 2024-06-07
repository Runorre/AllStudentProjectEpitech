/*
** EPITECH PROJECT, 2023
** Blank
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "lib.h"
    #include "op.h"
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "pc.h"
    #include "champ.h"
    #include "arg.h"
    #include "vm.h"

    int addprograminarena(vm *opt, char **arena);
    void print_hexa(char c);
    void showarena(char *arena, champ *p);
    vm *init(int ac, char **ar);
    int actionpgrm(pc **p, vm **machine);
    int checkarg(char argument, int (*tmppc)[2], arg_t *a, vm *machine);
    void actionforallpc(champ **p, vm **machine);
    int getarg(pc **p, arg_t *argu, vm **machine);
    int getarg_n(pc **p, int where, vm **machine);
    void fightmain(vm *machine);
    //Function VM
    int f_live(pc **p, vm **machine, arg_t *argu, short int function);
    int f_st(pc **p, vm **machine, arg_t *argu, short int function);
    int f_add(pc **p, vm **machine, arg_t *argu, short int function);
    int f_ldi(pc **p, vm **machine, arg_t *argu, short int function);
    int f_aff(pc **p, vm **machine, arg_t *argu, short int function);
    int f_sti(pc **p, vm **machine, arg_t *argu, short int function);
    int f_sub(pc **p, vm **machine, arg_t *argu, short int function);
    int f_and(pc **p, vm **machine, arg_t *argu, short int function);
    int f_ld(pc **p, vm **machine, arg_t *argu, short int function);
    int f_or(pc **p, vm **machine, arg_t *argu, short int function);
    int f_lld(pc **p, vm **machine, arg_t *argu, short int function);
    int f_lfork(pc **p, vm **machine, arg_t *argu, short int function);
    int f_lldi(pc **p, vm **machine, arg_t *argu, short int function);
    int f_fork(pc **p, vm **machine, arg_t *argu, short int function);
    int f_xjmp(pc **p, vm **machine, arg_t *argu, short int function);
    int f_xor(pc **p, vm **machine, arg_t *argu, short int function);
#endif /* !MY_H_ */
