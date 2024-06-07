/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/


#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "linked_list.h"
#include "struct.h"

#ifndef MY_H_
    #define MY_H_
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
    int my_show_word_array (char  *const *tab);
    char **my_str_to_word_array(char const *str);
    int check_place(maze *maze, wait_list *wait, closed_list *closed);
    int fonct(maze *maze_list, wait_list *wait, closed_list *closed);
    int place_wait(maze *maze, wait_list **wait, closed_list *closed);
    int move_tab(maze *maze, wait_list *wait, closed_list *closed);
    void display (closed_list *node);
    void insertposition (int pos, maze *maze, wait_list **head);
    void insertclose(closed_list **my_list, int i, int j, maze *maze);
    int place_path(closed_list *closed, maze *maze);
    int check_list(maze *maze, closed_list *closed);
    void display_wait (wait_list *node);

#endif /* !MY_H_ */
