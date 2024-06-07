/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** concat_params
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int len = 0;
    int a = 0;
    char *result;
    for (int i = 0; i != argc; i++) {
        len += my_strlen(argv[i]);
        len++;
    }
    len++;
    result = malloc(sizeof(char) * len);
    for (int i = 0; i != argc; i++) {
        int len2 = my_strlen(argv[i]);
        for (int e = 0; e != len2; e++) {
            result[a] = argv[i][e];
            a++;
        }
        result[a] = '\n';
        a++;
    }
    result[a - 1] = '\0';
    return (result);
}
