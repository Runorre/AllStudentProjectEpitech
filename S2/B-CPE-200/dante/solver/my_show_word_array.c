/*
** EPITECH PROJECT, 2022
** myshowwordarray.c
** File description:
** show tab
*/

#include "include/my.h"

int my_show_word_array (char  *const *tab)
{
    int i = 0;
    while (tab[i + 1] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    } my_putstr(tab[i]);
}

int my_show_int_array(int **tab)
{
    int i = 0, j = 0;
    while (tab[i] != NULL) {
        while (tab[i][j] != -1) {
            my_put_nbr(tab[i][j]);
            j++;
        }
        my_putchar('\n');
        i++;
        j = 0;
    }
}
