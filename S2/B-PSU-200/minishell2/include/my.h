/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <fcntl.h>


    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_putstrerr(char const *str);
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
    char *my_strcat(char *first, char *two);
    int my_strstartwith(char *start, char *str);
    int my_strcmp(char *str1, char *str2);


    int changedir(char **arg, char **env);
    int findinstrstr(char *find, char **str);
    int my_putstrstr(char **str);
    char **my_str_to_word_array2(char const *str, char pars);
    char *getinfopwd(char **env, int line);
    int terminal_main(char **word, char **env);
    void handler(int signal);
    int checkingexcute(char **word, char **env);
    int execute_process(char **command, char **env, char *path);
    int setenv_b(char **env, char **word);
    int unsetenv_b(char **env, char **word);
    int my_strstrlen(char **str);
    int checkalpha(char *word);
    int conditioncsm(char **word);
    int printerror(char *word);
    void order66(char **str);
    int checkmultycommand(char *buffer, char **env);
    int checkredirection(char **parsing);
    int my_strcontain(char *str, char search);
    int errorhandelingpipe(char *buffer, char **env);
    int checkpipe(char *command, char **env);
#endif /* !MY_H_ */
