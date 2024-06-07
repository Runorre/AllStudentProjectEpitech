/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** champ
*/

#ifndef CHAMP_H_
    #define CHAMP_H_
    #include "corewar.h"
    typedef struct champion {
        char *name;
        int a;
        int id;
        int start;
        int end;
        int wait;
        int live;
        int l_show;
        FILE *fd;
        pc *allpc;
        struct champion *next;
    }champ;
#endif /* !CHAMP_H_ */
