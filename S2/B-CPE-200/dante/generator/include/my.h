/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <time.h>
    #include <ulimit.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/resource.h>
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

    char **createstruct(int x, int y);
    list *addnode(list *current, int x, int y);
    int my_putstrstr(char **str);
    void nextmove(char **laby, list *file, position *pos);
    void imparfait(char **laby, int x, int y);
    int breakable(char **laby, int x, int y);
    int nextbacktrack(char **laby, position *pos, int x, int y);
    int antimazeimp(char **laby, int x, int y);
    int my_strcmp(char *str1, char *str2);

#endif /* !MY_H_ */
