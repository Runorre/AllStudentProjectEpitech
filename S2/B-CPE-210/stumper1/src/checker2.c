/*
** EPITECH PROJECT, 2023
** checker2
** File description:
** checker2
*/

#include "my.h"

int checkoption(char *option)
{
    int nooption = 1;
    int check = 0;
    for (int i = 1; option[i] != '\0'; i++) {
        nooption = 0;
        if (check == 1 && (option[i] >= '0' &&
                           option[i] <= '9'))
            check = 0;
        else if (check == 1)
            return print_error_num();
        if (option[i] != 'v' && option[i] != 'q' &&
            option[i] != 'c' && option[i] != 'n' &&
            !(option[i] >= '0' && option[i] <= '9'))
            return print_error_option(option[i]);
        if (option[i] == 'c' || option[i] == 'n')
            check = 1;
    }
    if (nooption || check)
        return print_error_option(' ');
    else
        return 0;
}
