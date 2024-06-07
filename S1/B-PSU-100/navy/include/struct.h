/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct map_a {
        char **joueur_map;
        char **enemy_map;
        int lose;
    }map_s;

    typedef struct systeme {
        int connect;
        int player;
        int pid_ennemie;
        char *info;
    }sys_data;

#endif
