/*
** EPITECH PROJECT, 2023
** lib
** File description:
** lib
*/

#ifndef _LIB_H_
    #define _LIB_H_

    void my_putchar(char c);
    int my_putnbr(int nb);
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
    int my_strcmp(char *str1, char *str2);
    int my_strstartwith(char *start, char *str);
    int findinstrstr(char *find, char **str);
    char *my_strcat(char *dest, char const *src);
    char **my_str_to_word_array(char *str);
    size_t my_strspn(const char *str, const char *charset);

#endif /* !_LIB_H_ */
