/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-solostumper02-angelo.anselmet
** File description:
** main.c
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void my_struppercase(char **ar)
{
    for (int i = 0; ar[1][i] != '\0'; i++) {
        if (ar[1][i] >= 'a' && ar[1][i] <= 'z') {
            ar[1][i] -= 32;
        }
    }
    for (int i = 0; ar[2][i] != '\0'; i++) {
        if (ar[2][i] >= 'a' && ar[2][i] <= 'z') {
            ar[2][i] -= 32;
        }
    }
}

int checker(int i, int e, char **ar)
{
    if ((ar[1][i] == ar[2][e]) &&
        (ar[1][i] != 1 || ar[2][e] != 1)) {
        ar[1][i] = 1;
        ar[2][e] = 1;
        return 1;
    }
    return 0;
}

int main(int ac, char **ar)
{
    if (ac < 3) {
        write(1, "Error: not enough arguments.\n", 29);
        return 84;
    }
    if (my_strlen(ar[1]) != my_strlen(ar[2])) {
        write(1, "no anagram!\n", 12);
        return 0;
    }
    int check = 0;
    my_struppercase(ar);
    for (int i = 0; ar[1][i] != '\0'; i++) {
        for (int e = 0; ar[2][e] != '\0'; e++) {
            check += checker(i, e, ar);
        }
    }
    if (check == my_strlen(ar[1]))
        write(1, "anagram!\n", 9);
    else
        write(1, "no anagram!\n", 12);
    return 0;
}
