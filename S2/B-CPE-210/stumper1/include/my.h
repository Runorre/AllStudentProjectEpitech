/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#define MY_H
    #ifndef MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    void my_putchar(char c);
    int my_put_nbr(int nbr);
    int my_putstr(char *str);
    int my_strlen(char *str);
    int my_strncmp(char *s1, char *s2, int nbr);
    int print_error_nofile(char *str);
    int print_error_option(char c);
    int print_error_num(void);
    int my_getnbr(char *str);
    void printnamefile(char *file);
    int checker(int ac, char **ar);
    int checkoption(char *option);
    int checkoptioncorrect(int ac, char **ar);

#endif /*MY_H_*/
