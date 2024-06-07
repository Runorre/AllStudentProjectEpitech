/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** arg
*/

#ifndef ARG_H_
    #define ARG_H_
    typedef struct agrument{
        int ar;
        int type;
        struct agrument *next;
    }arg_t;
#endif /* !ARG_H_ */
