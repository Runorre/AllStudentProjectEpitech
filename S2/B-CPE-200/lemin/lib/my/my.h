/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** no warning
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"
#ifndef _MY_H_
    #define _MY_H_

    void my_putchar(char c);
    int my_putnbr(int nb);
    void my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_compute_power_rec(int nb, int power);
    char *my_revstr(char *str);
    int my_nbrlen(int n);
    int my_unnbrlen(unsigned int n);
    int modulo_type(struct Dataf *data, va_list *ap);
    char *exa(unsigned int nb, int base, int maj);
    char *converter(unsigned int nb, int base, int maj, char *tab);
    int converter_int(int nb, int base, int maj);
    char majs(const char *str);
    int exa_adress(long unsigned int point);
    int my_put_unnbr(unsigned int nb);
    int my_put_longnbr(long nb);
    int modulo_type_l(struct Dataf *data, va_list *ap);
    char *converter_long(unsigned long nb, int base, int maj);
    int my_longnbrlen(long n);
    int my_unlongnbrlen(unsigned long n);
    int my_put_unlongnbr(unsigned long nb);
    int majletters(int maj);
    char *exa_long(unsigned long int nb, int base, int maj);
    int my_putfloat(double nb, int dec);
    int my_compute_power_rec(int nb, int p);
    int flagn(int *a, int counter);
    int nota_scient(double nb, int dec);
    int checkformat(struct Dataf *data);
    int checkformat_2(struct Dataf *data, int j);
    int pos(int nb, char *tab);
    int posspace(char *tab, int nbrlen, int check);
    int negspace(char *tab, int nbrlen);
    int defaultswitch(struct Dataf *data);
    int my_getnbr(char *str);
    size_t my_strspn(const char *str, const char *charset);
    void order67(char **str);

#endif /* MY_H_ */
