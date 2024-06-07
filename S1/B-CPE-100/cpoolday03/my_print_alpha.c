/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** A program show all alphabet on a single line
*/

#include <unistd.h>

int my_print_alpha(void)
{
    for (char letter = 97; letter != 123; letter++)
        write(1, &letter, 1);
}
