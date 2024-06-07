/*
** EPITECH PROJECT, 2022
** my_print_digits
** File description:
** function show all the digits on single line and in ascending order
*/

#include <unistd.h>

int my_print_digits(void)
{
    for (char number = 48; number != 58; number++)
        write(1, &number, 1);
}
