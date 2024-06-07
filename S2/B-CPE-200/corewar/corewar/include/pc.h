/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** pc
*/

#ifndef PC_H_
    #define PC_H_
    #include "corewar.h"
    typedef struct programcounter {
        int pc;
        int reg[REG_NUMBER];
        int wait;
        int carry;
        struct programcounter *next;
    }pc;
#endif /* !PC_H_ */
