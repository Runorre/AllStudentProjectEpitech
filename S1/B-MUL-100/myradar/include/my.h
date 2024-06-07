/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define PI   3.14159265358979323846264338327950288
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "struct.h"
    #include "systeme.h"
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

    int create_tower(char *line, ll_tower **current);
    int addinfo_p2(plane *tt, int num);
    int create_plane(char *line, ll_plane **current);
    int my_getnbr2(char *str);
    int init_radar(ll_plane *allplane, ll_tower *alltower);
    void loop_event(sys_data *sys);
    void radar(ll_plane *allplane, ll_tower *alltower, sys_data *sys);
    int init_radar(ll_plane *allplane, ll_tower *alltower);
    void set_rotation(plane *p);
    void checkcollision_ptp(ll_plane *allplane);
    void checktowerplane1(ll_plane *allplane, ll_tower *alltower);
#endif /* !MY_H_ */
