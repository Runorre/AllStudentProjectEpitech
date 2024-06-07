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
    #include <time.h>
    #include <string.h>
    #include <limits.h>
    #include <pwd.h>
    #include "lib.h"
    #include "list.h"
    #include "history.h"
    #include "systeme.h"

    int changedir(char **arg, char **env);
    int findinstrstr(char *find, char **str);
    int my_putstrstr(char **str);
    char **my_str_to_word_array2(char const *str, char pars);
    char *getinfopwd(char **env, int line);
    int terminal_main(char **word, systeme **sys);
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
    int alias_b(char **word, char **env, Element **alias);
    char **check_alias(char **word, systeme **sys);
    void insertion(Element **actuel, char *command, char *als);
    void afficherliste(Element *actuel);
    int count_quote(char **word, int i);
    char *stop_at_quote_tab(char **word, int i);
    int unalias_b(char **word, char **env, Element **alias);
    int checkmultycommand(systeme **sys);
    int checkredirection(char **parsing);
    int my_strcontain(char *str, char search);
    int where_function(char **word, char **env);
    int my_array_len(char **array);
    int which_function2(char **arg, char **allpath, int e);
    int where_function2(char **arg, char **allpath, int e);
    int which_function(char **arg, char **env);
    int errorhandelingpipe(systeme **sys);
    int checkpipe(char *command, systeme **sys);
    int echo_b(char **word,  char **env, int last);
    int command_existe(char **env, char **arg);
    int execute_process(char **command, char **env, char *path);
    int terminal_main2(char **word, systeme **sys);
    int addhistory(history **his, char *command, int id);
    int showhistory(history *his);
    void prompt(void);
    int ttymode(systeme **sys);
    int command_history(char **word, history *his);
    systeme *init_sys(char **env);
    int exclamation(char **word, history *his, systeme **sys);
    int is_a_builtin(char **arg, int e);
#endif /* !MY_H_ */
