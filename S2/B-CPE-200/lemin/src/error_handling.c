/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** error handling
*/
#include "../include/lem_in.h"

bool is_alphanum(char c)
{
    if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
        return false;
    }
    return true;
}

bool is_num(char c)
{
    if (c >= '0' && c <= '9') return true;
    return false;
}

int check_line(char *str)
{
    int i = 0;
    while (str[i]) {
        if (check_tunnel_line(str) == -1) {
            return -1;
        }
        if (str[i] == '-' && str[i - 1] != ' ' && str[i + 1] != ' ') {
            return 3;
        }
        if (str[i] == '#' && str[i + 1] != '#') return 0;
        if (str[i] == '#' && str[i + 1] == '#') return 2;
        if (is_alphanum(str[i]) == false && str[i] != ' ' && str[i] != '\n'
        && str[i] != '-' && str[i] != 0) {
            return -1;
        }
        i++;
    }
    return 0;
}

int check_commands(char *str)
{
    if (my_strcmp(str, "##start\n") == 0) return 1;
    if (my_strcmp(str, "##end\n") == 0) {
        return 2;
    } else {
        return -1;
    }
}

int check_errors(char **arr)
{
    int i = 0, w = 0, y = 0;
    if (my_getnbr(arr[0]) == 0) {
        return 84;
    }
    while (arr[i]) {
        if (check_line(arr[i]) == -1) {
            return -1;
        }
        if (check_line(arr[i]) == 2 && w != 5) {
            w = check_commands(arr[i]), y += check_commands(arr[i]);
        }
        if (check_line(arr[i]) == 3) {
            w = 5;
        }
        if (w <= -1) return -1;
        i++;
    }
    if (y != 3) return (-1);
    return 0;
}
