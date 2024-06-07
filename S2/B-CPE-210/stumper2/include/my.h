/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int flag_s(char **argv, int x);
int flag_g(char **argv);
char **my_str_to_word_array(char *str, int size);
void showzone(char **str);
int main_game(char **str);
int checkinside(char **str, char *check);
void modifyforwin(char **str, char *check);
void my_putstr(char *str);
void my_putchar(char c);
void checkword(char *str);
int my_strlen(char *str);
int not_loop_game(char **str, char *word);
int flag_w(char **argv, int x);
int check_game(char **str);
void notgoodmsg(char *str);
int all_flag(char **argv, int x);
int number_flag(char **argv);
int correct_string(char **argv);
int result(char **argv, int x);
void order66(char **str);
int checknext(char **str, int x, int y, char *word);
#endif /* MY_H_ */

