/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-antman-angelo.anselmet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct tocompress{
        char *word;
        int iteration;
        struct tocompress *next;
    }tocompress;
#endif /* !STRUCT_H_ */
