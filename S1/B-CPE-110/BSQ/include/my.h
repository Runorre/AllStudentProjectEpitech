/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#ifndef MY_H_
    #define MY_H_
int my_printf(char const *format, ...);
int my_strlen(char const *str);
void my_putstr(char const *str);
char *converter(unsigned int nb, int base, int maj, char *tab);
char *my_strcat(char const *dest, char const *src);
void my_putchar(char c);
char **my_str_to_word_array(char const *str);
int my_getnbr(char *str);
int checkifsquare(char **square);
int placevalue(int **finder, int x, int y);
int *searchbigsquare(int **square, int y_limte, int x_limte);
char checking(int *value, char c);
int my_getnbr2(char *str);
int bsq(char *av);
void my_putcharstar(char **square);
int checkneg(char *num);
int checklen(char *seed, int y);
int checkseed(char *seed);
int findbigsquare(char **square);
int bsq2(char **av);
int generate(char **ar);
#endif /* !MY_H_ */
