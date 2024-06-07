/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "struct.h"
    #include <stddef.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>
    #define _GNU_SOURCE
    extern siginfo_t *info_global;

    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_compute_power_rec(int nb, int power);
    char *my_revstr(char *str);
    int my_nbrlen(int n);
    int my_unnbrlen(unsigned int n);
    int my_put_unnbr(unsigned int nb);
    int my_put_longnbr(long nb);
    int my_longnbrlen(long n);
    int my_unlongnbrlen(unsigned long n);
    int my_put_unlongnbr(unsigned long nb);
    int my_putfloat(double nb, int dec);
    int my_compute_power_rec(int nb, int p);
    int my_getnbr(char *str);
    int my_printf(const char *format, ...);
    char **my_str_to_word_array(char const *str);


    map_s *ini_map(map_s *map);
    void print_map(map_s *map);
    int alpha_int(char *c);
    void save_joueur_map(map_s *map, char *line);
    int read_map(map_s *map, char *av);
    int verif_line(char *line, char c);
    int player1_connect(char *path, map_s *map);
    int player2_connect(int pid, char *path, map_s *map);
    void send_pos(int *pos, sys_data *sys);
    int *convertcood(int *pos);
    void iftouch(sys_data *sys, int *pos, map_s *map);
    int *get_pos(void);
    int verif_pos_ship(char **map, int *pos);
    void enemyattack(map_s *map, sys_data *sys);
    int game_p2(sys_data *sys, map_s *map);
    int game_p1(sys_data *sys, map_s *map);
    int *get_request_p(void);
    void verif_lose(map_s *map);
#endif
