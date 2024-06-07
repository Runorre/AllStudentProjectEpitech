/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenates a two string
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;
    for (int e = 0; src[e] != '\0'; e++) {
        dest[i] = src[e];
        i++;
    }
    dest[i + 1] = '\0';
    return dest;
}
