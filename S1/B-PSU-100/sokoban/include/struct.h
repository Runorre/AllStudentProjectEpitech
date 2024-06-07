/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-sokoban-angelo.anselmet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct data {
        char *path;
        int p_y;
        int p_x;
        int **co_o;
        int nbr_o;
        int nbr_x;
        char **map;
    } data;
#endif /* !STRUCT_H_ */
