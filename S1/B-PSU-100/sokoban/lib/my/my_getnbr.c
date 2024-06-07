/*
** EPITECH PROJECT, 2022
** my_get_nbr.c
** File description:
** get_nbr
*/

int my_getnbr(char *str)
{
    int i = 0, nb = 0, neg = 0, tmp = 0;
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb = ((nb * 10) + (str[i] - 48));
            tmp = 1;
        }if (str[i] != '-' && str[i] != '+' && tmp == 0) {
            return -1;
        }
        if (str[i - 1] == '-' && neg == 0 && tmp == 1) {
            neg = 2;
        }
        i++;
        tmp = 0;
    }
    if (neg == 2) {
        nb = nb * -1;
    }
    return nb;
}
