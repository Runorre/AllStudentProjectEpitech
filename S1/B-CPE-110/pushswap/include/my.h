/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "linked_list.h"
    #include "buffer.h"
    #include <stdlib.h>
    #include <unistd.h>
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

    struct node *create(char **av, int ac);
    struct node *addnode_2(struct node *list, int data);
    char *swap_elem(struct node *list, int who);
    char *rotate_left(struct node **list, int who);
    char *rotate_right(struct node **list, int who);
    char *swap_list(struct node **list_a, struct node **list_b, int who);
    int checkargu(char **av, int ac);
    int checkcomplete(struct node *list);
    int indicemin(struct node *list, int minus);
    void my_put_linkedlist(struct node *list);
    struct buffer createbuffer(void);
    void addtobuf(struct buffer *buf, char *str);
    void showfinal(struct buffer *buf);

#endif /* !MY_H_ */
