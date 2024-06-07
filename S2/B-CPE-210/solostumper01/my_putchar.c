/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-solostumper01-angelo.anselmet
** File description:
** Main
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
         i++;
    return i;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putdiffstr(char *str, int i)
{
    for (int e = i; str[e] != ' ' && str[e] != '\0'; e++)
        my_putchar(str[e]);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
