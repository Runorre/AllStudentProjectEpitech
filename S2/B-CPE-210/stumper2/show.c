/*
** EPITECH PROJECT, 2023
** Boggle
** File description:
** show
*/

#include "my.h"

void modifyforwin(char **str, char *check)
{
    int z = 0, i = 0, j = 0;
    while (str[j] != NULL) {
        if (str[j][i] == check[z] && check[z] != '\0') {
            str[j][i] -= 32;
            z++;
        }
        if (str[j][i] == '\0') {
            j++;
            i = 0;
        } else
            i++;
    }
}

void showzone(char **str)
{
    write(1, "+", 1);
    for (int i = 0; str[0][i] != '\0'; i++)
        write(1, "++", 2);
    write(1 , "++\n", 3);
    for (int j = 0; str[j] != NULL; j++) {
        write(1, "|", 1);
        for (int i = 0; str[j][i] != '\0'; i++) {
            write(1, " ", 1);
            write(1, &str[j][i], 1);
        }
        write(1, " |\n", 3);
    }
    write(1, "+", 1);
    for (int i = 0; str[0][i] != '\0'; i++)
        write(1, "++", 2);
    write(1 , "++\n", 3);
}

