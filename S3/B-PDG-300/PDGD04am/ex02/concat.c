/*
** EPITECH PROJECT, 2024
** Day04AM
** File description:
** concat
*/

#include <string.h>
#include <stdlib.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    int i1 = 0;
    int i2 = 0;

    *res = malloc((sizeof(char) * (strlen(str1) + strlen(str2) + 1)));
    while (str1[i1] != '\0') {
        (*res)[i1] = str1[i1];
        i1++;
    }
    while (str2[i2] != '\0') {
        (*res)[i1] = str2[i2];
        i1++;
        i2++;
    }
    (*res)[i1] = '\0';
}

void concat_struct(concat_t *str)
{
    int i1 = 0;
    int i2 = 0;
    int len1 = strlen(str->str1) + strlen(str->str2);

    str->res = malloc((sizeof(char) * (len1 + 1)));
    while (str->str1[i1] != '\0') {
        str->res[i1] = str->str1[i1];
        i1++;
    }
    while (str->str2[i2] != '\0') {
        str->res[i1] = str->str2[i2];
        i1++;
        i2++;
    }
    str->res[i1] = '\0';
}
