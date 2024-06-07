/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** no warning
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Clock.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "struct.h"

#ifndef MY_H_
    #define MY_H_

int my_getnbr(char *str);
int my_nbrlen(int n);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int main(void);
int my_put_unnbr(unsigned int nb);
void my_putchar(char c);
sfSprite *change_canva(canva_shape *canva, sfVector2i pos, sys_data *sys);
sfSprite *add_canva(canva_shape *canva);
int mousebutton_press(sys_data *sys, sfVector2f positon, sfVector2u size);
int mousebutton_click(sys_data *sys, sfVector2f positon, sfVector2u size);
sfRectangleShape *init_button (sfVector2f pos, sfVector2f size, sfColor color);
int inter_loop(sys_data *sys, sfColor sfGrey);
sfText *init_text (sfVector2f position, int size, char *str);
int is_in_canva(sys_data *sys, sfVector2f positon, sfVector2u size);
sfSprite *set_pencil(sys_data *sys);
sfSprite *set_eraser(sys_data *sys);
sfSprite *set_down(sys_data *sys);
sfSprite *set_up(sys_data *sys);
char *take_nbr(int nb);
char *my_strcat(char *dest, char const *src);
int change_size_up(sys_data *sys);
int change_size_down(sys_data *sys);
int loop_event(sys_data *sys);
void editmenu(sys_data *sys);
void initmenu(sys_data *sys);
void showmainbutton(sys_data *sys);
int mousebutton_hover(sys_data *sys, sfVector2f positon, sfVector2u size);
void actionmainbutton(sys_data *sys);
void hovermainbutton(sys_data *sys);
void pressmainbutton(sys_data *sys);
void animehover(sys_data *sys);
void animepress(sys_data *sys);
int mousebutton_press2(sys_data *sys, sfVector2f positon, sfVector2u size);
void actionfilebutton(sys_data *sys);
void hoverfilebutton(sys_data *sys);
void pressfilebutton(sys_data *sys);
int loop_event(sys_data *sys);
void file_event(sys_data *sys);
void presshelpbutton(sys_data *sys);
void hoverhelpbutton(sys_data *sys);
void actionhelpbutton(sys_data *sys);
void file_event(sys_data *sys);
void help_event(sys_data *sys);
void showhelpbutton(sys_data *sys);
void showfilebutton(sys_data *sys);
void buttoninteraction(sys_data *sys, sfRectangleShape *button);
void save_file(sys_data *sys);
void open_file(sys_data *sys);
void new_file(sys_data *sys);
#endif
