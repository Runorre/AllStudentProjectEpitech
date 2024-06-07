/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** is_all_digitis
*/

#include "myftp.h"

int is_all_digits(char *str)
{
    int i = 0;

    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}
