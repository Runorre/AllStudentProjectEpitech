/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** no warning
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <curses.h>
    #include "struct.h"
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
    char **getmap(char const *path);
    char **my_str_to_word_array(char const *str);
    struct data create_data(char *path);
    void keyevent(int key, struct data *d);
    void printo(struct data *jeu);
    int ifvictory(struct data *jeu);
    int iflose(struct data *jeu);
    void reset(struct data *jeu);
    char **create_map_em(char const *path);
    void checksize(char **map);
    void show(char **map);
#endif /* MY_H_ */
