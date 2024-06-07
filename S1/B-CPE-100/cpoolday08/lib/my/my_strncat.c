/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** concate
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;
    for (int e = 0; src[e] != '\0' && e != nb; e++) {
        dest[i] = src[e];
        i++;
    }
    dest[i + 1] = '\0';
    return dest;
}
